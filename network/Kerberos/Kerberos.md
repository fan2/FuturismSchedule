***SSO***（Single Sign On）是在多个应用系统中，用户只需要登录一次就可以访问所有相互信任（authenticated to each other）的业务子系统。  
***Kerberos*** 协议主要用于计算机网络的身份鉴别（Authentication），其特点是用户只需输入一次身份验证信息就可以凭借此验证获得的票据（Ticket-Granting Ticket）访问多个服务（seamlessly sign on at each system），即实现了 SSO。  
本篇节选自《[Authentication and Identification In Depth](https://developer.apple.com/library/content/documentation/Security/Conceptual/AuthenticationAndAuthorizationGuide/Authentication/Authentication.html#//apple_ref/doc/uid/TP40011200-CH4-SW1)》的 Common Types of Authentication|Kerberos，做了部分阅读笔记，翻译注解了认证流程细节，补充了交叉参考配图。  
先为自己留个坑，后面有空再完整翻译。  

## Concepts
> [Kerberos](https://en.wikipedia.org/wiki/Kerberos_%28protocol%29) is a computer network authentication protocol that works on the basis of 'tickets' to allow nodes communicating over a non-secure network to prove their identity to one another in a secure manner. 

In Greek mythology, Kerberos was the three-headed dog that guarded the gates of Hades. In computer security, Kerberos is an industry-standard protocol created by the Massachusetts Institute of Technology (MIT) to provide **authentication** over a network.

Kerberos is a *symmetric-key*, *server-based* protocol that is widely used in Macintosh, Windows, and UNIX networks. Kerberos has been integrated into OS X since OS X v10.1. Kerberos is highly secure, and unlike some other shared secret, private-key methods, it can be used for `one-to-many` and `many-to-many` communications as well as `one-to-one`. Kerberos achieves this ability by storing all users’ passwords in a ***central location***, the *directory server*. Kerberos can be used for any number of users and servers on a network.

OS X works with all common directory servers, including LDAP (Lightweight Directory Access Protocol) servers and Microsoft Windows Active Directory servers. OS X Server includes an open source LDAP server.

Kerberos works by passing around **Kerberos tickets**—blocks of data used to *identify* a user who has been *previously authenticated*. These tickets are issued for a specific user, service, and period of time. Because the initial Kerberos ticket is a form of identification, a kerberized application can use that ticket to request access to additional kerberized services *without* requiring the user to *reauthenticate* (by reentering the user’s password). (A kerberized service or application is one that has been configured to support Kerberos tickets.) This ability to access additional services without reauthentication is called *`single sign-on`*(***SSO***).

OS X can host Kerberos authentication services (called a *`Key Distribution Center`* (***KDC***)). Any OS X Server installation that is configured to include a shared LDAP server automatically includes a Kerberos v5 KDC. The Kerberos server software is also included in the client version of OS X.

Although users’ passwords cannot be intercepted during authentication (because they are *never* sent over the network), it is very important to keep the machine containing the directory server in a secure location. All passwords and private encryption keys are stored in the directory server and are therefore vulnerable to attack if a malicious person gains access to the server.

Any user with an iCloud account can use Kerberos over the Internet to access and control a computer remotely—a service known as Back To My Mac. This service uses public key cryptography to authenticate the two computers, which then follow standard Kerberos protocols, with one computer acting as the **KDC** and the other as the **Kerberos client**. The protocol that defines the use of public key cryptography for initial authentication in Kerberos is known as PKINIT. You use the open-source `Generic Security Service Application Program Interface` (***GSS-API***) to adapt your application to use Kerberos.

## [Scenario](http://searchsecurity.techtarget.com/tip/Kerberos-configuration-as-an-authentication-system-for-single-sign-on)
Kerberos should be considered if an organization is looking for a mature means of authenticating users to ***multiple*** applications **across** a variety of technologies.

It is also worth considering if a company has a Web presence that directs end users to a ***portal*** with several different applications providing underlying functionality. A bank is a great example of this: users could have a combination of a checking account, a savings account, an IRA or a mortgage from the same bank. It would be a much better user experience to have a single set of credentials for conducting business than to log in to each of these accounts separately.

Kerberos is intended to help enable **centralized authentication** to simplify the user experience and the system administrators' account management process. It can be a useful technology and is worth examining by any organization exploring single sign-on systems.

## Kerberos Authentication Process
There are several phases to Kerberos authentication.  

In the **first** phase, the client obtains credentials (blocks of data that identify and authenticate an entity) to be used to request access to kerberized services.  
In the **second** phase, the client requests authentication for a specific service.  
In the **final** phase, the client presents those credentials to the service.

[![kerberos-ticket-exchange](https://docs.typo3.org/typo3cms/extensions/ig_ldap_sso_auth/_images/kerberos-ticket-exchange.png)](https://docs.typo3.org/typo3cms/extensions/ig_ldap_sso_auth/SSO/Kerberos.html)

Figure 1-2 and Figure 1-3 illustrate this process.

### requests credentials from the Kerberos KDC
Figure 1-2 shows the first phase, in which the ***client***, labeled Alice in the figure, requests credentials from the Kerberos KDC.

![Figure 1-2  Requesting credentials from the KDC](https://developer.apple.com/library/content/documentation/Security/Conceptual/AuthenticationAndAuthorizationGuide/Art/kerberos_1_2x.png)

The steps are as follows:

1. Alice looks up the user ID for her username using a directory server.  
	Alice then sends a request to the KDC asking for credentials, providing that *user ID* (in cleartext).  
	
	> Alice 发送携带明文 ID 向  KDC 请求 TGT 凭据。  
	>> 首次登录时，Alice 需输入账户密码（不会在网络上传输明文密码），由 KDC（authentication server）认证通过后，才能 revisit 发送 TGTGT 报文执行 `Request for TGT`。  
	
	The KDC gets Alice’s *password* from the directory server, and applies a **hashing** function to it, thus turning it into a ***temporary encryption key***. This temporary key is known as Alice’s ***secret key***.  
	
	> KDC 根据 user ID 查找密码；对密码进行哈希加盐（Hashing with Salt）作为 Alice’s Secret Key（GTKey）。  

	>> [如何正确对用户密码进行加密？](http://www.infoq.com/cn/articles/how-to-encrypt-the-user-password-correctly)  
	>> [两次 MD5 加密用户密码](http://www.songzhenjiang.cn/post/347.html)，[适当提高安全性](http://www.cftea.com/c/2008/12/LKAR2X3VDALTAI88.asp)。  
	>> [使用MD5对用户密码加密与解密](http://blog.csdn.net/e295166319/article/details/53585238)  
	>> [how to crack md5(md5(pwd)+string) hashes](https://hashcat.net/forum/thread-1338.html)  
	>> [先用md5，再用sha1，这样密码会安全一点吗？](https://www.zhihu.com/question/21668719)  

2. The KDC creates an encryption key called a ***session key*** for use by Alice the next time she wants to request service from a kerberized server, and **encrypts** that key with the Alice’s *secret key*.  
	
	> KDC 为 Alice 创建 Session Key，用于后续 Alice 向 KDC 请求服务通信加密。  
	> KDC 使用 Alice’s Secret Key 加密 Session Key（***GTKey_TGT***）。  
	>> 只有客户 Alice 自己和 KDC（根据 ID 向 directory server 查询） 知道 Alice 的密码，一般客户不会泄露密码，**安全性**主要由 KDC（directory server）保障。  
	
	It also creates an identification credential called a *ticket-granting ticket* (***TGT***), which contains a copy of the session key encrypted with the *KDC’s secret symmetric key* (plus other information).  
	
	> 同时，KDC 使用 Secret Key 加密 Session Key 生成等效凭据——***TGT***（authentication token）。  
	>> TGT 只有颁发者 KDC 才能解开，**安全性**由 KDC（ticket-granting server）保障。  
	>> TGT（大票）是后续申请授权业务服务 ST（小票）的凭证。  
	
	Both the *session key* and the *TGT* include **timestamps** and **expiration times** to limit the chances of their being intercepted and used by unauthorized persons.  
	
	> KDC 颁发的 Session Key 和生成的 TGT 均带有时间戳和有效期。
	
	The KDC sends both credentials to Alice, along with information about how to **transform** Alice’s password into her *secret key*.  
	
	> KDC 将 TGT、GTKey_TGT 以及哈希加盐算法信息一并发给 Alice。
	
	Because Alice knows her password, Alice uses it, along with that hash information, to compute her *secret key*. Alice then uses her secret key to decrypt the *session key* and stores it for later. She can’t decrypt the TGT or modify it, but saves it for later use as well.
	
	> Alice 根据哈希加盐算法基于密码计算出 Secret Key，然后从 GTKey_TGT 解密出 Session Key。  
	>> （1）Session Key 用于后续 Alice 向 KDC 请求服务（如下文中 Alice 请求与 Bob 建立会话）时的通信加密。  
	>> （2）TGT 是 Alice 首次登录成功后，换回的认证凭据。Alice 无法解密 KDC 加密的 TGT，也无法篡改 TGT。后续 Alice 在向 KDC 请求连线业务服务（kerberized service）时，无需再键入账户密码（reauthenticate），只需携带 TGT 给 KDC 即可识别是否已认证过的客户（的合法请求）。  

### Authenticating the client and server with a Kerberos ticket
In the second phase, Alice uses the **TGT** to request ***identification credentials*** from the KDC in order to use a kerberized service, labeled Bob in the figure. Because Alice has a TGT, the KDC *does not have to reauthenticate* her, so Alice is not asked again for her password.

> [SSO](https://en.wikipedia.org/wiki/Single_sign-on) ***shares*** centralized authentication servers that all other applications and systems use for authentication purposes and combines this with techniques to ensure that users *do not* have to actively enter their credentials *more than once*.

In the third phase, Alice sends the *credentials* to Bob, and Bob sends *authentication information* to Alice. The second and third phases are illustrated in Figure 1-3.

![Figure 1-3  Authenticating the client and server with a Kerberos ticket](https://developer.apple.com/library/content/documentation/Security/Conceptual/AuthenticationAndAuthorizationGuide/Art/kerberos_2_2x.png)

The steps are as follows:

1. Alice sends two messages to the KDC:  
	- An **authenticator**—a request to *open a session* with Bob that includes the client ID ad a timestamp—encrypted using the **session key**  
		> Alice 请求建立与 Bob（业务 server）的会话，发送一个使用 Session Key 加密的包含 ID 和 时间戳 的 authenticator 请求。  
		>> **疑问**：Request for Bob 中的 Bob’s ID 不包含在 authenticator 报文中，应该是明文部分？  

	- A message that contains the **TGT** that the KDC issued earlier  
		> Alice 发送 KDC 早先颁发的 TGT。  
	
2. The KDC **decrypts** the TGT and extracts the *session key* it issued earlier to Alice. (Recall that when the KDC sent the session key to Alice earlier, it was encrypted with Alice’s secret key, so only the KDC and Alice can know this session key.) Because the TGT is encrypted with the KDC’s secret key, it cannot have been altered, and thus the KDC trusts that session key.  
	>  KDC 使用私钥解密出 TGT 中 Alice 的 Session Key。  
	> 由于 TGT 是 KDC 使用私钥加密的，因此只有 KDC 能解开。  

	The KDC obtains Alice’s client ID by using the *main session key* to decrypt the authenticator.  
	> KDC 使用 Session Key 解密出 authenticator 中 Alice’s ID，得知 Alice 想与 Bob 通信。  

	The KDC then generates a new ***client-server session key*** for Alice to use when communicating with Bob, encrypts it with the *main session key*, and sends it to Alice.  
	> KDC 生成一个 Alice-Bob 会话 C-S Session Key，使用 Main Session Key 加密（***GTKey_ST***）后发回给 Alice。  
	>> Alice 使用 Main Session Key 即可从 GTKey_ST 解密出 C-S Session Key。

	The KDC also creates a **ticket** for Alice to send to Bob. This ticket contains a new session key, and Alice’s client ID. This key is encrypted with *Bob’s secret key*, so Alice (or an intruder) cannot read or modify it. The KDC sends this ticket to Alice.  
	> 同时，KDC 将创建一个 Alice 向 Bob 请求服务的票据（***ST***，Service Ticket，小票）返回给 Alice，再由 Alice 发给 Bob。  
	> ST 票据包含 Alice’s ID 和与 Bob 会话的 C-S Session Key，使用 Bob 的私钥进行加密。  

3. Alice sends the ticket to Bob. Alice also sends a new authenticator (client ID and timestamp) encrypted using the *client-server session key*.  
	> Alice 将 KDC 颁发的 ST 票据发给 Bob；同时发送一个新的 authenticator，其中包含 ID 和时间戳，使用 C-S Session Key 加密。  
	>> 这里的时间戳应该和第1步中的时间戳不是同一个，根据第4步这个时间戳可能是 KDC 某个报文的回复时间（received earlier from the KDC）？  

	Bob decrypts it with his secret key. Because only the KDC and Bob know his secret key, Bob knows the ticket was issued by the KDC. Bob extracts the *client-server session key*.  
	> Bob 使用私钥解密出 ST 票据中的会话 C-S Session Key。  
	>> 至此，通过 KDC 的认证勾兑，Alice 和 Bob 获取到了属于他们之间业务会话的 C-S Session Key。  

	Bob uses the client-server session to decrypt the authenticator. It then sends back a message containing the timestamp from the authenticator plus one, encrypted using the session key.  
	> Bob 使用 C-S Session Key 解密出 authenticator（其中包含 Alice’s ID 和 时间戳），对时间戳+1后再使用 C-S Session Key 发回给 Alice。  

4. Because Alice knows that only she and Bob have this session key, she knows that the credential must have come from Bob. She checks the value and compares it with the one she received earlier from the KDC. If they are off by one (as expected), she knows that the Bob *has been authenticated* by the KDC.  
	> 由于发起者 Alice 知道只有她和 Bob 拥有属于他们的 C-S Session Key，因此若 Alice 使用  C-S Session Key 能解密出报文中的时间戳，并且与自己创建  authenticator 中的时间戳比较，如果相差1，说明 Bob 是通过 KDC 授权认证的（业务 server）。  
	>> 接下来，Alice 和 Bob 之间即可通过 C-S Session Key （对称）加密进行安全地通信。  

```
假设 Bob 是文件业务接入服务器，Alice 从 KDC 获取授权 ST 与 Bob 校验后即可接入文件业务：  
1.Alice 基于 C-S Session Key 加密的安全消息通道向 Bob 请求上传/下载文件；  
2.Bob 基于 C-S Session Key 加密的安全消息通道回应文件存储的 IP、PORT、URI、UUID 等信息；  
3.Alice 再通过 HTTP/HTTPS(TLS) 连接文件存储服务器（`IP:PORT/URI?key=UUID`）请求上传（POST）/下载（GET）文件。  
```

Note that this procedure does not involve sending either Alice’s or Bob’s secret key over the network. Because both Alice and Bob are **authenticated** to each other, Bob knows that Alice is a valid user and Alice knows that Bob is the server with which she intended to do business. All credentials are *further protected* with *timestamps* and *expiration times*. Kerberos has other security features as well; for details, see the MIT Kerberos website at [MIT's kerberos page](http://web.mit.edu/kerberos/).

## Kerberos and Authorization
Kerberos is an ***authentication*** protocol, not an ***authorization*** protocol. That is, it verifies the identities of both the client and the server, but it *does not* include any information about *whether* the client has a right to use the services provided by the server. In terms of the preceding discussion, after Bob is satisfied that the request for services really came from Alice, it is up to Bob to determine whether to **grant** Alice access to those services. The ticket(ST) that Bob receives from Alice contains enough information about Alice to enable Bob to make that determination.

Starting with Kerberos version 5, Kerberos tickets provide a mechanism for the tamperproof transmission of authorization information. When the client requests a ticket, it includes information about itself in the request and can request that the KDC include additional authorization in the ticket. The KDC inserts this information into the authorization data field of the ticket and forwards it to the server. Kerberos does not define how this authorization information should be encoded; it provides only a secure mechanism for its transmission. It is up to the client and server to implement the authorization protocol.

## Single Sign-on
OS X uses Kerberos for single sign-on authentication, which relieves users from entering a name and password *separately* for *every* kerberized service. With single sign-on, after a user enters a name and password in the login window, the user **does not** have to enter a name and password for Apple file service, mail service, or other services that use Kerberos authentication. In other words, Kerberos authenticates the user ***once***, and thereafter uses tickets to ***identify*** the user.

To take advantage of the single sign-on feature, services must be configured for Kerberos authentication and users and services must use the **same** Kerberos KDC. In OS X, user accounts in an LDAP directory that have a password type of Open Directory use the server’s built-in KDC. These user accounts are automatically configured for Kerberos and single sign-on. The server’s kerberized services also use the server’s built-in KDC and are automatically configured for single sign-on.

## Large Networks
At a high level, you can usually think of the Kerberos Key Distribution Center (KDC) as a single entity. However, a KDC consists of **two** separate software processes: **`the authentication server`** and the **`ticket-granting server`**. *The authentication server* verifies a user’s identity by prompting the user for a name and password and asking the directory server for the user’s password. The authentication server then looks up the user’s secret key, generates a session key, and creates the ticket-granting ticket (TGT), as shown in Figure 1-4(revisited same as Figure 1-2).

[![Figure 8-1 General Process for Kerberos Ticket Exchange](http://www.cisco.com/c/dam/en/us/td/i/100001-200000/180001-190000/183001-184000/183467.ps/_jcr_content/renditions/183467.jpg)](http://www.cisco.com/c/en/us/td/docs/security/nac/appliance/configuration_guide/49/cas/49cas-book/s_adsso.html)

Thereafter, the user sends the TGT to *the ticket-granting server* whenever the services of a kerberized server are required, and the ticket-granting server issues the ticket, as shown in Figure 1-5(revisited same as Figure 1-3).

[![Figure 1: Basic Transactions in the Kerberos Protocol](https://msdn.microsoft.com/en-us/library/bb742456.ntks01_big.gif)](https://msdn.microsoft.com/en-us/library/bb742456.aspx)

> 后续（subsequent）访问 Network Resource 业务，只需携带业务服务小票（ST）即可。

Many networks are too large to efficiently store all the information about users and computers in a single directory server. Instead, a distributed model is used, where there are a number of directory servers, each serving a subset of the network. In Kerberos parlance, this subset is referred to as a ***realm***（domain，域）. Each realm has its *own* ticket-granting server and authentication server. If a user needs *a ticket for a service* in a different realm（Cross-Realm，跨域）, the authentication server(`KDC1`) issues a TGT(`TGT1`) and the user sends the TGT to the authentication server, as before. The authentication server then issues a ticket(`TGT2`), *not* for the desired service *but for* the *remote* ticket-granting server(`KDC2`) for the realm that the service is in. The user then sends the ticket(`TGT2`) to the remote ticket-granting server to *get the ticket*(`ST`) for the actual service(`Network Resource`).

[![Figure 2: Cross-Realm Referrals](https://i-msdn.sec.s-msft.com/dynimg/IC15653.gif)](https://msdn.microsoft.com/en-us/library/bb742456.aspx)

In fact, in a large network, the user might have to contact the remote ticket-granting server in a sequence of realms before finally getting the ticket for the desired service. When a ticket for the application service is finally issued, it contains an enumeration of all the realms consulted in the process of requesting the ticket. An application server that applies strict authorization rules is permitted to reject authentication that passes through realms that it does not trust.
