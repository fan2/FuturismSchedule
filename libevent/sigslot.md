[sigslot](http://sigslot.sourceforge.net/)  - C++ Signal/Slot Library  

[C++11](https://github.com/supergrover/sigslot), [C++14](https://github.com/palacaze/sigslot)  

1. 返回值必须为 void  
2. slot 参数个数范围为0-8个  
3. 提供 slot 接口实现的类必须继承自 has_slots<>  

## connect

连接绑定的语法：

```c
sig_trigger.sig.connect(&socket, &Socket::slot);
```

触发器 sig_trigger 声明成员变量 sig（函数模板），插座 socket 拥有成员函数 slot（插槽），**connect** 将 sig 与 slot 相连。
这里可以理解为函数模板的实例化，可类比 C 中的函数指针赋值指向类成员函数。可见，sig 和 slot 的接口必须匹配，即实例和模板的参数个数要求一致。

- 可以将多个 sig 连接到1个 slot 上，这样可以有多个触发器来触发 sig 信号，适合抽象基础公共行为接口；  
- 也可以将一个 sig 连接到多个 slot 上，这样每次 sig 发出信号的时候，每个连接的 slot 都能收到该信号，适合总闸惊群模式。  

## disconnect

通过调用 sig 的 disconnect 函数断开 sig 和 slot 之间的连接，disconnect 只有一个参数——目的对象的地址。

```c
sig_trigger.sig.disconnect(&slot_socket);
```

一般不需要显式调用 disconnect 函数，在 sig 类和目的类（继承 has_slots 的类）析构函数中将自动调用 disconnect 断开连接。

## refs

### 介绍

sigslot 介绍：[Gtalk](https://blog.csdn.net/ouyangbuxiu/article/details/1915510)，[libjingle](https://blog.csdn.net/smallcraft/article/details/2237802)，[WebRTC](https://blog.csdn.net/volvet/article/details/52269876)  

### 剖析

[WebRTC 中的事件处理机制深入剖析](https://juejin.im/post/59ee2044f265da43271765af)  

[sigslot signals across threads](https://stackoverflow.com/questions/38790071/sigslot-signals-across-threads)  

## demo

### Switch-Light

灯控示例：

```cpp
class Switch
{
public:
     signal0<> Clicked;
};

class Light : public has_slots<>
{
public:
     void ToggleState();
     void TurnOn();
     void TurnOff();
};

Switch sw1, sw2;
Light lp1, lp2;
sw1.Clicked.connect(&lp1, &Light::ToggleState);
sw2.Clicked.connect(&lp2, &Light::ToggleState);
```

继承 `has_slots<>` 的类 light 的成员函数 `void ToggleState();` 称之为 **slot**；而 switch 类的成员变量 `signal0<> Clicked;` 称之为 **sig**。  

以上示例中，声明了2个灯和开关，开关1（2）与灯1（2）相连，开关1（2）控制灯1（2）。  
Switch.Clicked 被连接到 Light.ToggleState，按下 Switch 即将控制信号 sig 传递到绑定的信号槽 slot，控制灯 Light 的状态。  
sigslot 的核心就是通过 sig 和 slot 建立对应关系来实现对象间的消息交互。  
绑定关系是在运行期建立的，跟 Swtich 和 Light 本身的设计无关。

灯和开关连线后，即可按下开关，通过开关实施对灯的状态控制：

```cpp
    sw1.Clicked();
    sw1.Clicked();
    sw2.Clicked();
```

假设开关默认是关的，则 `sw1.Clicked` 相当于开灯，再调用一次相当于关灯。

### WebRTC

```cpp
class VideoCapturer : public sigslot::has_slots<>,
                      public rtc::VideoSourceInterface<cricket::VideoFrame> {
    // ...
    sigslot::signal2<VideoCapturer*, const CapturedFrame*, sigslot::multi_threaded_local> SignalFrameCaptured;
};

void VideoCapturer::Construct() {
    enable_camera_list_ = false;
    capture_state_ = CS_STOPPED;
    SignalFrameCaptured.connect(this, &VideoCapturer::OnFrameCaptured);
    scaled_width_ = 0;
    scaled_height_ = 0;
    enable_video_adapter_ = true;
    // There are lots of video capturers out there that don't call
    // set_frame_factory.  We can either go change all of them, or we
    // can set this default.
    // TODO(pthatcher): Remove this hack and require the frame factory
    // to be passed in the constructor.
    set_frame_factory(new WebRtcVideoFrameFactory());
}

void SignalCapturedFrame(cricket::CapturedFrame* frame) {
    SignalFrameCaptured(this, frame);
}
```
