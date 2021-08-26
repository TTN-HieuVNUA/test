package com.hieu.model;

import java.util.ArrayList;
import java.util.List;

public class Student {
    private String maSinhVien;
    private String tenSinhVien;
    private String maLop;
    private List<Course> danhSachKhoaHocDangKi = new ArrayList<Course>();

    public Student() {
    }

    public Student(String maSinhVien, String tenSinhVien, String maLop) {
        this.maSinhVien = maSinhVien;
        this.tenSinhVien = tenSinhVien;
        this.maLop = maLop;
    }

    // getter - setter
    public String getMaSinhVien() {
        return maSinhVien;
    }

    public void setMaSinhVien(String maSinhVien) {
        this.maSinhVien = maSinhVien;
    }

    public String getTenSinhVien() {
        return tenSinhVien;
    }

    public void setTenSinhVien(String tenSinhVien) {
        this.tenSinhVien = tenSinhVien;
    }

    public String getMaLop() {
        return maLop;
    }

    public void setMaLop(String maLop) {
        this.maLop = maLop;
    }

    public List<Course> getDanhSachKhoaHocDangKi() {
        return danhSachKhoaHocDangKi;
    }

    public void setDanhSachKhoaHocDangKi(List<Course> danhSachKhoaHocDangKi) {
        this.danhSachKhoaHocDangKi = danhSachKhoaHocDangKi;
    }

    @Override
    public String toString() {
        return "Student{" +
                "maSinhVien='" + maSinhVien + '\'' +
                ", tenSinhVien='" + tenSinhVien + '\'' +
                ", maLop='" + maLop + '\'' +
                ", danhSachKhoaHocDangKi=" + danhSachKhoaHocDangKi +
                '}';
    }
}
