!Factorial using do for 1 to 10 numbers
program factorial
implicit none 
integer::nfact=1
integer::n
do n=1,10
 nfact=nfact*n 
 write(*,*)n,nfact
 end do
end program factorial
