#include "func.h"

#include <cctype>

namespace {

    bool isSign(const char* a, int& n) {

        if (a[n] == '+' || a[n] == '-') {

            n++;

            return true;

        }

        return false;

    }

    bool isDigit(const char* a, int& n) {

        if (std::isdigit(a[n])) {

            return true;

        }

        return false;

    }

    bool isInteger(const char* a, int& n) {

        bool r = isDigit(a, n);

        if (r && a[n] != '\0') {

            n++;

            isInteger(a, n);

        }

        return r;

    }

    bool isExponent(const char* a, int& n) {

        int N = n;

        if (a[N] == 'E') {

            N++;

            if (isSign(a, N) && isInteger(a, N)) {

                n = N;

                return true;

            }

            else if (isInteger(a, N)) {

                n = N;

                return true;

            }

        }

        return false;

    }

    bool isMantiss(const char* a, int& n) {

        int N = n;

        if (a[N] == '.') {

            N++;

            if (isInteger(a, N)) {

                n = N;

                return true;

            }

        }

        N = n;

        if (isInteger(a, N)) {

            n = N;

            return true;

        }

        return false;

    }

    bool isReal(const char* a, int& n) {

        int N = n;

        if (isSign(a, N) && isMantiss(a, N) && isExponent(a, N)) {

            n = N;

            return true;

        }

        N = n;

        if (isMantiss(a, N) && isExponent(a, N)) {

            n = N;

            return true;

        }

        return false;

    }

}

bool funcs::isReal(const char* a) {

    int n = 0;

    return ::isReal(a, n) && a[n] == '\0';

}