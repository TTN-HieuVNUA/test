package com.hieu.service;

import com.hieu.dao.StudentDB;
import com.hieu.model.Student;

import java.util.ArrayList;
import java.util.List;

public class StudentService {

    public List<Student> getAllSinhVien() {
        StudentDB studentDB = new StudentDB();
        return studentDB.getStudentList();
    }

    public void xooaSinhVien(String maSV) {

    }
}
