#include<iostream>
#include<exception>
#include<string>

// Definición de la clase de excepción personalizada
class miexcepcion : public std::exception {
private:
    std::string mensaje;
public:
    explicit miexcepcion(const std::string& msg) : mensaje(msg) {}
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

void lanzaExcepcion() {
    throw miexcepcion("Ocurrió un error en la función lanzaExcepcion");
}
int main() {
    try {
        lanzaExcepcion();
    }
    catch (const miexcepcion& e) {
        std::cout << "Excepción capturada: " << e.what() << std::endl;
    }

    return 0;
}