package com.hieu.dao;

import com.hieu.model.Course;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class CourseDb {

    private static List<Course> courseList = new ArrayList<Course>();


    static {
        Course course01 = new Course("khoa01");
        Course course02 = new Course("khoa02");
        Course course03 = new Course("khoa03");
        courseList.add(course01);
        courseList.add(course02);
        courseList.add(course03);
    }

    public static List<Course> getCourseList() {
        return courseList;
    }

    public static void setCourseList(List<Course> courseList) {
        CourseDb.courseList = courseList;
    }

}
