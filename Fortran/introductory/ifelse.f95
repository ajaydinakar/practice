!if else program
program ifels
implicit none
integer::x
read(*,*) x
if(x .lt. 5)then
  write(*,*)"number less than 5"
  else if (x .eq. 5)then
    write(*,*)"number equal 5"
  else
    write(*,*)"number greaterthan 5"
    end if
end program ifels
