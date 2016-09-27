!program on function parameter passing and returning
program functn
integer::a,b,c!declaring variables
read(*,*)a,b!reading a,b at run time
c=sum(a,b)!call function
write(*,*)c
contains 
!function definition
function sum(x,y)
integer::x,y,sum!declaring variables and functname
sum=x+y!returning value
end function
end program functn
