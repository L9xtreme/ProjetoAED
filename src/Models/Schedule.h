#ifndef PROJETOAED_SCHEDULE_H
#define PROJETOAED_SCHEDULE_H
#include <string>

using namespace std;

enum WeekDay {Monday, Tuesday, Wednesday, Thursday, Friday};
enum ScheduleType {T, TP, P};

class Schedule {
    private:
        WeekDay weekday;
        double startHour;
        double duration;
        ScheduleType type;

    public:
        Schedule(WeekDay weekday, double startHour, double duration, ScheduleType type);

        WeekDay getWeekday();
        double getStartHour();
        double getDuration();
        ScheduleType getType();

        static WeekDay weekdayFromString(const string& wday);
        static ScheduleType typeFromString(const string& stype);

};


#endif //PROJETOAED_SCHEDULE_H