!one dimensional and 2D Array using vectors
program vectors
integer::v(10)
integer,dimension(3,3)::vb
do i=1,10
  v(i)=i
  end do
  do i=1,3
    do j=1,3
      vb(i,j)=i+j
      end do
      end do
  write(*,*)"array 1 is",v
  write(*,*)"array 2 is",vb
end program vectors
