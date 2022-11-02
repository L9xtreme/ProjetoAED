#ifndef PROJETOAED_SCHEDULE_H
#define PROJETOAED_SCHEDULE_H
#include <string>
#include <vector>

using namespace std;

enum WeekDay {Monday=0, Tuesday=1, Wednesday=2, Thursday=3, Friday=4};
enum ScheduleType {T, TP, P};

class Schedule {
    private:
        WeekDay weekday;
        double startHour;
        double duration;
        ScheduleType type;
        string ucCode;
        string classCode;

    public:
        Schedule(WeekDay weekday, double startHour, double duration, ScheduleType type, string ucCode, string classCode);

        WeekDay getWeekday();
        double getStartHour();
        double getDuration();
        ScheduleType getType();
        string getUcCode();
        string getClassCode();

        static WeekDay weekdayFromString(const string& wday);
        static ScheduleType typeFromString(const string& stype);
        static string weekDayToString(const WeekDay& weekDay);
        static string typeToString(const ScheduleType& sType);
        static void sortSchedule(vector<Schedule>& schedule);

};


#endif //PROJETOAED_SCHEDULE_H