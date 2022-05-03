
#include "SinglyOrderedList.h"
#include <iostream>
#include <algorithm>

int main() {

    SinglyOrderedList singlyOrderedList;

    SinglyOrderedList singlyOrderedList1;

    singlyOrderedList1.add("7");
    singlyOrderedList1.add("0");

    SinglyOrderedList singlyOrderedList2;

    singlyOrderedList.add("2");

    singlyOrderedList.add("1");
    singlyOrderedList.add("4");

    singlyOrderedList.add("3");

    singlyOrderedList.print();

    singlyOrderedList.deleteWord("4");

    singlyOrderedList.deleteWord("1");

    singlyOrderedList.print();

    singlyOrderedList.add(singlyOrderedList1);

    singlyOrderedList.print();

    singlyOrderedList1.print();

    singlyOrderedList1.add("2");

    singlyOrderedList1.print();

    singlyOrderedList.deleteWord(singlyOrderedList1);

    singlyOrderedList.print();

    singlyOrderedList1.add("0");

    set_intersection(singlyOrderedList, singlyOrderedList1, singlyOrderedList2);

    singlyOrderedList2.print();

    return 0;

}
