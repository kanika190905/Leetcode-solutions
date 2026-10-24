
class Solution {
public:
    int convert(int month, int date, int days[]) {
        for (int i = 1; i < month; i++) {
            date += days[i];
        }
        return date;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int AAdate = (arriveAlice[3]-'0')*10 + (arriveAlice[4]-'0');
        int AAmonth = (arriveAlice[0]-'0')*10 + (arriveAlice[1]-'0');

        int BAdate = (arriveBob[3]-'0')*10 + (arriveBob[4]-'0');
        int BAmonth = (arriveBob[0]-'0')*10 + (arriveBob[1]-'0');

        int ALdate = (leaveAlice[3]-'0')*10 + (leaveAlice[4]-'0');
        int ALmonth = (leaveAlice[0]-'0')*10 + (leaveAlice[1]-'0');

        int BLdate = (leaveBob[3]-'0')*10 + (leaveBob[4]-'0');
        int BLmonth = (leaveBob[0]-'0')*10 + (leaveBob[1]-'0');

        int days[] = {0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        int start = max(convert(AAmonth, AAdate, days),
                        convert(BAmonth, BAdate, days));

        int end = min(convert(ALmonth, ALdate, days),
                      convert(BLmonth, BLdate, days));

        return max(0, end - start + 1);
    }
};
