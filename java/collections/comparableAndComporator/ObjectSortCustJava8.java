import java.util.*;
import java.util.stream.Collectors;

class ObjectSortCustJava8 {


    public static void main(String[] args)
    {
        List<Student> students=new ArrayList<Student>();
        students.add(new Student(2,"mani","wilmington_unniversity"));
        students.add(new Student(1,"ajay","mwsu"));
        students.add(new Student(3,"bhanu","illionis_state_univ"));
        students.add(new Student(4,"krishna","mwsu"));
        students.add(new Student(5,"ajay","mwsu"));
        students.add(new Student(6,"ajay","AU"));
        System.out.println("Before sorting "+students);
        Comparator<Student> sortByName=Comparator.comparing(Student::getName);
        Comparator<Student> sortByCollege=Comparator.comparing(Student::getCollege);
        Comparator<Student> sortById=Comparator.comparing(Student::getId);
        //this combines three  comparisions to one
        Comparator<Student> sortByOrder=Comparator.comparing(Student::getName).thenComparing(Student::getCollege).thenComparing(Student::getId);
        // these are sorting using java8 method reference and previous collections.sort
        Collections.sort(students,sortByName);
        System.out.println("After sorting by Name \n"+students);
        Collections.sort(students,sortByCollege);
        System.out.println("After sorting by College \n"+students);
        Collections.sort(students,sortById);
        System.out.println("After sorting by Id \n"+students);
        Collections.sort(students,sortByOrder);
        System.out.println("After sorting by combing two name then college \n"+students);
        // these are sorting using java8 list.sort
        students.sort(sortByName);
        System.out.println("After sorting by Name \n"+students);
        students.sort(sortByCollege);
        System.out.println("After sorting by College \n"+students);
        students.sort(sortById);
        System.out.println("After sorting by Id \n"+students);
        //Using streams
        students=students.stream().sorted(sortByName).collect(Collectors.toList());
        System.out.println("After sorting by Name with streams \n"+students);

    }

}



class Student  {

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
    public String toString() {
        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", college='" + college + '\'' +
                '}';
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCollege() {
        return college;
    }

    public void setCollege(String college) {
        this.college = college;
    }
}
