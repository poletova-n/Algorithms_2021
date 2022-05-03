//
// Created by Администратор on 21.02.2022.
//

#ifndef ALGORITHMS_2021_GLOSSARY_H
#define ALGORITHMS_2021_GLOSSARY_H

#include "SinglyOrderedList.h"
#include "ranges"

class Glossary : public SinglyOrderedList {

private:

    struct GlossaryNode : public Node{

        SinglyOrderedList* wordList_;

        GlossaryNode(const std::string &item, Node *next);

        ~GlossaryNode();
    };

public:

    //Glossary();

    int getFullSize();

    bool add(const std::string& key) override;

    void print() override;

    bool deleteWord(const std::string& key) override;

    bool deleteWord(Glossary& list);

    bool deleteSection(const std::string& key);

    bool add(Glossary &list);

    int find(const std::string& key) override;

    static void intersection(Glossary& glossary1, Glossary& glossary2 , Glossary& result);
};


#endif //ALGORITHMS_2021_GLOSSARY_H
