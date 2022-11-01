#include "Schedule.h"

using namespace std;

Schedule::Schedule(WeekDay weekday, double startHour, double duration, ScheduleType type){
    this -> weekday = weekday;
    this -> startHour = startHour;
    this -> duration = duration;
    this -> type = type;
}

WeekDay Schedule::getWeekday() {
    return this -> weekday;
}

double Schedule::getStartHour() {
    return this -> startHour;
}

double Schedule::getDuration() {
    return this -> duration;
}

ScheduleType Schedule::getType() {
    return this -> type;
}

WeekDay Schedule::weekdayFromString(const string& wday) {
    if (wday == "Monday") return Monday;
    else if (wday == "Tuesday") return Tuesday;
    else if (wday == "Wednesday") return Wednesday;
    else if (wday == "Thursday") return Thursday;
    else return Friday;
}

ScheduleType Schedule::typeFromString(const string& stype) {
    if (stype == "T") return T;
    else if (stype == "TP") return TP;
    else if (stype == "P") return P;
}



