#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {

    size_t number_count;
    cin >> number_count;

    vector<double> numbers(number_count);
    cerr << "Enter numbers: ";
    for (size_t i = 0; i < number_count; ++i)
        cin >> numbers[i];

    vector<double> NepovtoruNumbers;

    for (size_t i = 0; i < numbers.size(); ++i) {
        bool povtor = false;

        for (size_t j = 0; j < numbers.size(); ++j) {
            if (i != j && fabs(numbers[i] - numbers[j]) < 1e-9) {
                povtor = true;
                break;
            }
        }

        if (!povtor) {
            NepovtoruNumbers.push_back(numbers[i]);
        }
    }

    cerr << "Nepovtor Numbers (" << NepovtoruNumbers.size() << "): ";
    for (double x : NepovtoruNumbers)
        cerr << x << " ";
    cerr << endl;

    size_t bin_count;
    cin >> bin_count;

    double min = NepovtoruNumbers[0];
    double max = NepovtoruNumbers[0];
    for (double x : NepovtoruNumbers) {
        if (x < min)
            min = x;
        else {
            if (x > max)
                max = x;}
    }

    double bin_size = (max - min) / bin_count;

    vector<size_t> bins(bin_count);
    for (size_t i = 0; i < NepovtoruNumbers.size(); ++i) {
        bool found = false;
        for (size_t j = 0; j < bin_count - 1 && !found; ++j) {
            double lo = min + j * bin_size;
            double hi = min + (j + 1) * bin_size;
            if (NepovtoruNumbers[i] >= lo && NepovtoruNumbers[i] < hi) {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
            bins[bin_count - 1]++;
    }

    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 4;

    size_t max_count = bins[0];
    for (size_t count : bins) {
        if (count > max_count)
            max_count = count;
    }

    for (size_t i = 0; i < bin_count; ++i) {
        if (bins[i] < 100)
            cout << " ";
        if (bins[i] < 10)
            cout << " ";
        cout << bins[i] << " | ";

        size_t height = (max_count > MAX_ASTERISK)? static_cast<size_t>(MAX_ASTERISK * (static_cast<double>(bins[i]) / max_count)): bins[i];

        for (size_t j = 0; j < height; ++j)
            cout << "*";
        cout << "\n";
    }

    return 0;
}
