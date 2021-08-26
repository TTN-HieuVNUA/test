package com.hieu.execution;

import com.hieu.model.Course;
import com.hieu.model.Student;
import com.hieu.service.CourseService;
import com.hieu.service.StudentService;

import java.util.List;

public class MainProgram {

    public static void main(String[] args) {

        StudentService studentService = new StudentService();
        List<Student> allSinhVien = studentService.getAllSinhVien();
        allSinhVien.forEach(student -> System.out.println(student));

    }
}
