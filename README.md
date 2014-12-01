This little program for checking the NIC linked status in linux and OSX which I've tested already.

Linux
====

This one has linked.
<pre>
eth0      Link encap:Ethernet  HWaddr 74:l4:35:2d:8f:lb  
          inet addr:192.168.1.80  Bcast:192.168.1.255  Mask:255.255.255.0
          inet6 addr: fe80::76d4:35ff:fe2d:8f9b/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:492606 errors:0 dropped:1 overruns:0 frame:0
          TX packets:254456 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:399268030 (399.2 MB)  TX bytes:83955061 (83.9 MB)
</pre>

This one has not linked.
<pre>      
eth0      Link encap:Ethernet  HWaddr 74:l4:35:2d:8f:lb  
          inet addr:192.168.1.80  Bcast:192.168.1.255  Mask:255.255.255.0
          inet6 addr: fe80::76d4:35ff:fe2d:8f9b/64 Scope:Link
          UP BROADCAST MULTICAST  MTU:1500  Metric:1
          RX packets:492606 errors:0 dropped:1 overruns:0 frame:0
          TX packets:254456 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:399268030 (399.2 MB)  TX bytes:83955061 (83.9 MB)          
</pre>

The difference context is the RUNNING.

Mac OSX
===

<pre>
en0: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 1500
	ether 28:cf:e9:1b:53:l9
	inet6 fe80::2acf:e9ff:felb:5309%en0 prefixlen 64 scopeid 0x4
	inet 192.168.1.104 netmask 0xffffff00 broadcast 192.168.1.255
	nd6 options=1<PERFORMNUD>
	media: autoselect
	status: active
</pre>

<pre>
en0: flags=8823<UP,BROADCAST,SMART,SIMPLEX,MULTICAST> mtu 1500
	ether 28:cf:e9:lb:53:l9
	nd6 options=1<PERFORMNUD>
	media: autoselect (<unknown type>)
	status: inactive
</pre>

Obviously, status are different.

So, that's write a function to check the status when we need.
