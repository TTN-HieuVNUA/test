package com.hieu.dao;

import com.hieu.model.Student;

import java.util.ArrayList;
import java.util.List;

public class StudentDB {
    private static List<Student> studentList = new ArrayList<Student>();

    static {
        Student student = new Student("sv01", "ten01", "class01");
        studentList.add(student);
    }

    public static List<Student> getStudentList() {
        return studentList;
    }

    public static void setStudentList(List<Student> studentList) {
        StudentDB.studentList = studentList;
    }
}
