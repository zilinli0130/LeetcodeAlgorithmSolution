# 630. Course Schedule III

###### Tag: Priority Queue, Sort

This problem asks for the max number of courses we could take by given a set of deadlines. We could firstly sort the dealines in the ascending order so that we could
finish the courses which have priority deadlines. If we can't finish a course in time, a priority queue is used to keep track of the past course which have the max duration,
we want to remove this course to ensure that we spend the least number of days to take max number of courses.
