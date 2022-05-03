
#include "SinglyOrderedList.h"
#include "Glossary.h"
#include <iostream>
#include <algorithm>

int main() {

    Glossary glossary;

    Glossary glossary2;

    Glossary glossary3;

    glossary2.add("gay");

    glossary2.add("sex2");

    glossary2.add("sex");

    glossary.add("sex");

    glossary.add("sfx");

    glossary.add("zxc");

    glossary.add("cum");

    glossary.print();

    std::cout << "===" << std::endl;

    glossary2.print();

    Glossary::intersection(glossary, glossary2, glossary3);

    std::cout << "===" << std::endl;

    glossary3.print();

    std::cout << "===" << std::endl;

    std::cout << glossary3.find("sex") << std::endl;

    std::cout << glossary3.find("se2x") << std::endl;

    std::cout << glossary.find("zxc") << std::endl;

}
