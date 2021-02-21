#include "hospitalData.h"
#include <sstream>

/* print hospital data */
std::ostream& operator<<(std::ostream &out, const hospitalData &HD) {
    out << "Hosptial Info: " << HD.getState();
    out << "\nOverall rating (out of 5): " << HD.getOverallRate();
    out << "\nmortality rating: " << HD.mortality.getRating();
    out << "\nreadmission rating:" << HD.readmission.getRating();
    return out;
}
