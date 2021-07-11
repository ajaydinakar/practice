import java.util.*;

class ObjectSortNatural {


    public static void main(String[] args)
    {
        List<Student> students=new ArrayList<Student>();
        students.add(new Student(1,"ajay","mwsu"));
        students.add(new Student(2,"mani","wilmington"));
        students.add(new Student(3,"bhanu","illionis"));
        students.add(new Student(4,"krishna","mwsu"));
        System.out.println("Before sorting "+students);
        Collections.sort(students);
        System.out.println("After sorting "+students);
    }

}
class Student  implements  Comparable<Student>{

    private int id;
    private String name;
    private String college;

    public Student() {
    }

    public Student(int id, String name, String college) {
        this.id = id;
        this.name = name;
        this.college = college;
    }

    @Override
    public int compareTo(Student o) {
        return this.name.compareTo(o.name);
    }

    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", college='" + college + '\'' +
                '}';
    }
}
