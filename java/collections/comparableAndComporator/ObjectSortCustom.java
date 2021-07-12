import java.util.*;

class ObjectSortCustom {


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
        Collections.sort(students,new SortByCollege());
        System.out.println("After sorting by college "+students);
        Collections.sort(students,new SortByName());
        System.out.println("After sorting by name "+students);
        Collections.sort(students,new SortById());
        System.out.println("After sorting by Id "+students);
        Collections.sort(students,new SortByOrder());
        System.out.println("After sorting by order(by name then college and  then id) if attributes are same "+students);
    }

}

class SortByName implements Comparator<Student>
{

    @Override
    public int compare(Student o1, Student o2) {
        return o1.getName().compareTo(o2.getName());
    }
}
class SortByCollege implements Comparator<Student>
{

    @Override
    public int compare(Student o1, Student o2) {
        return o1.getCollege().compareTo(o2.getCollege());
    }
}
class SortById implements Comparator<Student>
{

    @Override
    public int compare(Student o1, Student o2) {
        return o1.getId()- o2.getId();
    }
}
class SortByOrder implements Comparator<Student>
{

    public int compare(Student o1, Student o2) {
        int result=o1.getName().compareTo(o2.getName());
        if(result==0)
        {
            result=o1.getCollege().compareTo(o2.getCollege());
            if(result==0)
            {

            }
        }
        return result;
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
