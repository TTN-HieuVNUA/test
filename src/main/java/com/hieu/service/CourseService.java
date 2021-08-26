package com.hieu.service;

import com.hieu.dao.CourseDb;
import com.hieu.model.Course;

import java.util.List;

public class CourseService {
	
    public List<Course> getAllCourses() {
        CourseDb courseDb = new CourseDb();
        List<Course> courseList = courseDb.getCourseList();

        return courseList;
    }

    public List<Course> themMoiKhoaHoc(Course course) {
        // get all courses
        List<Course> courseList = getAllCourses();

        // add new course
        courseList.add(course);
        return courseList;
    }

    public void xoaKhoaHoc(String maKhoaHocId) {
        List<Course> allCourses = getAllCourses();
        allCourses.removeIf(course -> course.getMaKhoaHoc().equalsIgnoreCase(maKhoaHocId));
    }

}
