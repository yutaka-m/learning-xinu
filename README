# Xinu executable environment with qemu-system-i386

## How to use

```
$ git clone git@github.com:yutaka-m/learning-xinu.git
$ cd learning-xinu
$ docker build -t xinu-qemu-system-i386 .
$ docker run -it xinu-qemu-system-i386 sh
$ qemu-system-i386 -m 16 -kernel build/compile/xinu.elf -nographic -append "console=ttyS0"
```

## Example

```
$ docker run -it xinu-qemu-system-i386 sh
# qemu-system-i386 -m 16 -kernel build/compile/xinu.elf -nographic -append "console=ttyS0"

Xinu for Vbox -- version #92  (root)  Sun Aug 11 17:28:37 UTC 2024

   4550648 bytes of free memory.  Free list:
           [0x00145000 to 0x0009FFF7]
           [0x00100000 to 0x005FBFFF]
    115401 bytes of Xinu code.
           [0x00100000 to 0x0011C2C8]
    148488 bytes of data.
           [0x0011FEC0 to 0x001442C7]

�����E�������DCc�Sc57*������E�������DCc�Sc57*�

�����E�������DCc�Sc57*������E�������DCc�Sc57*�
�����E�������DCc�Sc57*�DHCP failed to get a response
Cannot obtain an IP address




------------------------------------------
   __    __   _____    _   _    _    _
   \ \  / /  |__ __|  | \ | |  | |  | |
    \ \/ /     | |    |  \| |  | |  | |
    / /\ \    _| |_   | \   |  | |  | |
   / /  \ \  |     |  | | \ |  \  --  /
   --    --   -----    -   -     ----
------------------------------------------


Welcome to Xinu!


xsh $
```

