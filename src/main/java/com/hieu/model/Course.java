package com.hieu.model;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Course {
    private String maKhoaHoc;
    private Date thoiGianBatDau;
    private Date thoiGianKetThuc;
    private Subject tenMonHoc;
    private List<Student> danhSachSinhVien = new ArrayList<Student>();

    public Course() {
    }

    public Course(String maKhoaHoc) {
        this.maKhoaHoc = maKhoaHoc;
    }

    public Course(String maKhoaHoc, Date thoiGianBatDau, Date thoiGianKetThuc, Subject tenMonHoc) {
        this.maKhoaHoc = maKhoaHoc;
        this.thoiGianBatDau = thoiGianBatDau;
        this.thoiGianKetThuc = thoiGianKetThuc;
        this.tenMonHoc = tenMonHoc;
    }

    public Course(String maKhoaHoc, Date thoiGianBatDau, Date thoiGianKetThuc, Subject tenMonHoc, List<Student> danhSachSinhVien) {
        this.maKhoaHoc = maKhoaHoc;
        this.thoiGianBatDau = thoiGianBatDau;
        this.thoiGianKetThuc = thoiGianKetThuc;
        this.tenMonHoc = tenMonHoc;
        this.danhSachSinhVien = danhSachSinhVien;
    }

    public String getMaKhoaHoc() {
        return maKhoaHoc;
    }

    public void setMaKhoaHoc(String maKhoaHoc) {
        this.maKhoaHoc = maKhoaHoc;
    }

    public Date getThoiGianBatDau() {
        return thoiGianBatDau;
    }

    public void setThoiGianBatDau(Date thoiGianBatDau) {
        this.thoiGianBatDau = thoiGianBatDau;
    }

    public Date getThoiGianKetThuc() {
        return thoiGianKetThuc;
    }

    public void setThoiGianKetThuc(Date thoiGianKetThuc) {
        this.thoiGianKetThuc = thoiGianKetThuc;
    }

    public Subject getTenMonHoc() {
        return tenMonHoc;
    }

    public void setTenMonHoc(Subject tenMonHoc) {
        this.tenMonHoc = tenMonHoc;
    }

    public List<Student> getDanhSachSinhVien() {
        return danhSachSinhVien;
    }

    public void setDanhSachSinhVien(List<Student> danhSachSinhVien) {
        this.danhSachSinhVien = danhSachSinhVien;
    }

    @Override
    public String toString() {
        return "Course{" +
                "maKhoaHoc='" + maKhoaHoc + '\'' +
                ", thoiGianBatDau=" + thoiGianBatDau +
                ", thoiGianKetThuc=" + thoiGianKetThuc +
                ", tenMonHoc=" + tenMonHoc +
                ", danhSachSinhVien=" + danhSachSinhVien +
                '}';
    }
}
