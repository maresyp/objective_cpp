//
// Created by Mateusz Pysera on 07/12/2021.
//

class Bryla {
public:
    virtual int pole() {
        return 0;
    }

    virtual int objetosc() {
        return 0;
    }

    virtual int przekotna() {
        return 0;
    }

};

class Kula : public Bryla {
public:
    int pole() override {
        return 0;
    }

    int objetosc() override {
        return 0;
    }

protected:
    ~Kula() = default;

};

class Prostopadloscian : public Bryla {
public:
    int pole() override {
        return 0;
    }

    int objetosc() override {
        return 0;
    }

    int przekotna() override {
        return 0;
    }

protected:
    ~Prostopadloscian() = default;
};

class Ostroslup : public Bryla {
public:
    int pole() override {
        return 0;
    }

    int objetosc() override {
        return 0;
    }

    int przekotna() override {
        return 0;
    }

protected:
    ~Ostroslup() = default;
};

int main(int argc, char *argv[], char *envp[]) {

    return 0;
}