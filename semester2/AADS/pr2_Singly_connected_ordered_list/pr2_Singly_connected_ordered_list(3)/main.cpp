
#include "SinglyOrderedList.h"
#include "Glossary.h"
#include <iostream>
#include <algorithm>

void showAddDeleteFind();

void showAdd();

void showDelete();

void showInc();

int main() {

    return 0;
}

void showAddDeleteFind(){

    Glossary glossary;

    glossary.add("taxi"); glossary.add("toxic"); glossary.add("sus");
    glossary.add("amogus"); glossary.add("ammo");

    std::cout << (glossary.add("taxi") ? "Added" : "No") << std::endl;

    std::cout << (glossary.deleteWord("sussy") ? "Deleted" : "No") << std::endl;

    std::cout << (glossary.add("tts10") ? "Added" : "No") << std::endl;

    glossary.print();

    std::cout << glossary.getFullSize() << std::endl;

    std::cout << glossary.find("ammo") << " " << glossary.find("sss") << " " << glossary.find("toxic") << std::endl;

    std::cout << (glossary.deleteWord("amogus") ? "Deleted" : "No") << std::endl;

    glossary.deleteWord("sus"); glossary.deleteWord("toxic");

    glossary.print();
}

void showAdd(){

    Glossary glossary1, glossary2;

    glossary1.add("taxi"); glossary1.add("toxic"); glossary1.add("sus");

    glossary2.add("amogus"); glossary2.add("ammo"); glossary2.add("tts10"); glossary2.add("sus");

    std::cout << "Glossary 1: " <<std::endl;
    glossary1.print();

    std::cout << "Glossary 2: " <<std::endl;
    glossary2.print();

    glossary1.add(glossary2);

    std::cout << "Glossary 1: " <<std::endl;
    glossary1.print();

    std::cout << "Glossary 2: " <<std::endl;
    glossary2.print();
}

void showDelete(){

    Glossary glossary1, glossary2;

    glossary1.add("taxi"); glossary1.add("toxic"); glossary1.add("sus");
    glossary1.add("amogus"); glossary1.add("ammo"); glossary1.add("tts10");

    glossary2.add("taxi"); glossary2.add("ammo");glossary2.add("sus");glossary2.add("lol");

    std::cout << "Glossary 1: " <<std::endl;
    glossary1.print();

    std::cout << "Glossary 2: " <<std::endl;
    glossary2.print();

    glossary1.deleteWord(glossary2);

    std::cout << "Glossary 1: " <<std::endl;
    glossary1.print();

    std::cout << "Glossary 2: " <<std::endl;
    glossary2.print();
}

void showInc(){

    Glossary glossary1, glossary2, glossary3;

    glossary1.add("taxi"); glossary1.add("toxic"); glossary1.add("sus");
    glossary1.add("amogus"); glossary1.add("ammo"); glossary1.add("tts10");

    glossary2.add("taxi"); glossary2.add("ammo");glossary2.add("sus");
    glossary2.add("lol"); glossary2.add("amo"); glossary2.add("kek");

    std::cout << "Glossary 1: " <<std::endl;
    glossary1.print();

    std::cout << "Glossary 2: " <<std::endl;
    glossary2.print();

    Glossary::intersection(glossary1, glossary2, glossary3);

    std::cout << "Glossary 3: " <<std::endl;
    glossary3.print();

}