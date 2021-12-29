//
// Created by Mateusz Pysera on 07/12/2021.
//

class TestTime {
public:
    virtual int read_file_vr();

    int read_file_non_vr();
};

int TestTime::read_file_vr() {
    // TODO : open file and write content to variable
    return 0;
}

int TestTime::read_file_non_vr() {
    // TODO : open file and write content to variable
    return 0;
}

class ChildTestTime : public TestTime {

};

int main() {
    ChildTestTime cht = ChildTestTime();
    return 0;
}

