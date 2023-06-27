core0:

coh1 equ 0x10200000

   mov eax,coh1
   mov dword [es:eax], 0x2000
   mov	ebx, dword [eax]
   cmp ebx, 0x2000
	\\individual test case goes here

   jne failed


core1:
   mov ecx,coh5
   loop1:

   mov eax, dword [es:ecx]
   cmp eax,0xaaaaaaaa
   jne loop1

   coh2 equ 0x10300000
   mov ecx,coh2
   mov ebx, dword [es:ecx]
   cmp dword [es:ecx], 0x2000

   jne failed

   
   
   coh3 equ 0x10400000
   mov edx, coh3
   mov dword [es:edx] , 0x4000
   cmp dword [es:edx] , 0x4000
   jne failed 

   jmp passed






   mov edx, 0x8000
   mov dword [es:edx], 0x66666666
   lock add dword [es:edx],0x11111111
   mov eax,[es:edx]
   cmp eax, 0x77777777
   jne failed