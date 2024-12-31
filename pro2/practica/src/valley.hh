/** @file valley.hh

    @brief Contiene las declaraciones de la clase `Valley` y declaraciones de
   los tipos usados por `Valley`.
*/
#ifndef VALLEY_HH
#define VALLEY_HH

#include "city.hh"

#ifndef NO_DIAGRAM
#include <unordered_map>
#include <vector>

#include "BinTree.hh"
#endif

/// @brief Relaciona el peso y volumen de un mismo producto
struct Product {
    /// @brief El peso del producto por unidad
    int weight = -1;

    /// @brief El volumen del producto por unidad
    int volume = -1;

    /// @brief Crea un producto con el peso y volumen dados.
    Product(int w, int v) : weight(w), volume(v) {}
};

/// @brief Define el barco que viaja por `Valley`.
struct Ship {
    /// @brief El identificador del producto que quiere comprar
    size_t buy_id = 0;

    /// @brief  La cantidad que se quiere comprar
    int buy_count = 0;

    /// @brief El identificador del producto que quiere vender
    size_t sell_id = 0;

    /// @brief  La cantidad que se quiere vender
    int sell_count = 0;

    /// @brief Lista de los nombres de las ultimas ciudades visitadas en cada
    /// viaje
    std::vector<std::string> last_travels;

    /// @brief Las direcciones que puede tomar el barco al viajar
    enum class Direction {
        /// @brief Sirve para indicar que ha habido un error al escoger
        /// la direccion
        None,

        /// @brief El barco ha ido hacia la izquierda
        Left,

        /// @brief El barco ha ido hacia la derecha
        Right,
    };
};

/// @brief `Valley` define el rio, contiene y maneja las ciudades. El programa
/// principal interactua directamente con esta clase. Es, también, una capa de
/// abstracción entre la entrada del usuario y las demas clases.
class Valley {
   private:
    /// @brief Define una ruta que puede tomar el barco. Tambien la cantidad de
    /// productos que compra y vende a lo largo del viaje.
    struct RouteData {
        /// @brief La cantidad de productos que se vende en total en la ruta
        int sell_count = 0;

        /// @brief La cantidad de productos que se compran en total en la ruta
        int buy_count = 0;

        /// @brief Devuelve el total de productos comprados y vendidos.
        /// Mide la eficiencia de la ruta.
        ///
        /// @pre cierto
        /// @post total() > 0
        inline int total() const { return sell_count + buy_count; }
    };

   public:
    /// @brief Pone todos los miembros de clase a sus valores iniciales
    Valley() = default;
    ~Valley() = default;

    /// @brief Lee un nuevo rio por la entrada. Borra el rio anterior. Borra las
    /// rutas del barco anterior, matiene sus valores.
    ///
    /// @pre cierto
    /// @post `mCityNames` es un `BinTree<T>` con T == std::string, no vacio.
    void readRiver();

    /// @brief Modifica los valores del barco. No cambia el vector de las rutas
    /// anteriores.
    ///
    /// @pre cierto
    /// @post El barco compra y vende productos distintos. Almenos una cantidad
    /// es estrictamente positiva.
    void readShip();

    /// @brief Imprime los valores de compra y de venta del barco. Tambien las
    /// ciudades de las rutas anteriores. No usado. Solo esta para ver la
    /// estrucura del rio.
    void printShip() const;

    /// @brief Anade productos al vector de productos global
    /// @param quantity La cantidad de productos a anadir.
    ///
    /// @pre `quantity` > 0
    /// @post se han anadido productos al vector global
    void addProducts(int quantity);

    /// @brief Comprueva que la id de un producto es valida.
    /// @param id La id que comprobar
    /// @return true si es valida, false otherwise
    ///
    /// @pre cierto
    /// @post No hay cambios en el estado
    bool isValidProduct(size_t id) const;

    /// @brief Consulta la cantidad de productos en el vector de productos
    /// global
    /// @return La cantidad de productos
    ///
    /// @pre cierto
    /// @post No hay cambios en el estado
    static size_t numProducts();

    /// @brief Imprime por consola el peso y volumen de un producto
    /// @param index La id del producto a imprimir
    ///
    /// @pre El producto puede no ser valido
    /// @post No hay cambios en el estado
    void printProduct(int index) const;

    /// @brief Lee por consola el inventario de una ciudad. Borra el inventario
    /// anterior
    /// @param name El nombre de la ciudad
    ///
    /// @pre La ciudad tiene que ser valida
    /// @post No hay cambios en el estado
    void readCityInventory(const std::string& name);

    /// @brief Anade un producto al inventario de una `City`
    /// @param name El nombre de la `City`
    /// @param id El identificador del producto
    /// @param has La cantidad de `Product` que tiene la `City`
    /// @param needs La cantidad de `Product` que necesita la `City`
    ///
    /// @pre `name` tiene que ser un id de ciudad valido. `id` tiene que ser un
    /// producto valido
    /// @post Se ha anadido el producto dado a la ciudad dada
    void addToCityInventory(const std::string& name, size_t id, int has,
                            int needs);

    /// @brief Elimina un producto de una ciudad
    /// @param name El nombre de la `City`
    /// @param id El identificador del producto
    ///
    /// @pre `name` tiene que ser un id valido. `id` tiene que ser un producto
    /// valido
    /// @post Se ha eliminado el producto dado de la ciudad dada
    void removeFromCityInventory(const std::string& name, size_t id);

    /// @brief Consulta si una ciudad es valida, es decir, existe en el mapa
    /// @param name El nombre de la `City`
    /// @return true si la ciudad existe, false otherwise
    ///
    /// @pre `name` puede no ser valido.
    /// @post No hay cambios en el estado
    bool isValidCity(const std::string& name) const;

    /// @brief Consulta si una ciudad tiene un producto en su inventario
    /// @param name El nombre de la `City`
    /// @param id El identificador del producto
    /// @return true si la ciudad tiene el producto, false otherwise
    ///
    /// @pre La `id` tiene que ser valida. `name` tiene que ser valida
    /// @post No hay cambios en el estado
    bool hasProduct(const std::string& name, size_t id) const;

    /// @brief Escribe por consola una ciudad
    /// @param name La `City` que escribir
    ///
    /// @pre La ciudad tiene que existir en el rio
    /// @post No ha cambios en el estado. Los datos de la ciudad sale por
    /// consola.
    void printCity(const std::string& name) const;

    /// @brief Consulta el peso y volumen total del inventario de una ciudad
    /// @param name El nombre de la `City`
    /// @param mass (out) El peso total del inventario
    /// @param vol (out) El volumen total del inventario
    ///
    /// @pre La ciudad tiene que existir en el rio
    /// @post No hay cambios en el estado
    void getCityMassVol(const std::string& name, int& mass, int& vol) const;

    /// @brief Consulta el peso y volumen de un producto en una ciudad
    /// @param name El nombre de la `City`
    /// @param id El identificador del producto
    /// @param mass (out) El peso del producto
    /// @param vol (out) El volumen del producto
    ///
    /// @pre La ciudad tiene que existir en el rio. El producto tiene que ser
    /// valido.
    /// @post No hay cambios en el estado
    void getCityProduct(const std::string& name, size_t id, int& mass,
                        int& vol) const;

    /// @brief Hace la funcion `trade` con las ciudades dadas
    /// @param c1 Una de las ciudades
    /// @param c2 La otra ciudad
    ///
    /// @pre Las ciudades tienen que ser validas
    /// @post Los inventarios de las ciudades se han actualizado segun las
    /// reglas de `trade`
    void trade(const std::string& c1, const std::string& c2);

    /// @brief Hace la funcion `redistribute` con las ciudades dadas
    ///
    /// @pre El árbol del río tiene que ser no vacio
    /// @post Se ha comerciado con las ciudades rio arriba recursivamente
    void redistribute();

    /// @brief Encuentra la ruta mas provechosa y la recrea con el barco.
    ///
    /// @pre El árbol del río tiene que ser no vacio
    /// @post El barco ha viajado por el rio realizando la ruta mas provechosa
    void travel();

    /// @brief Consulta el vector de productos global
    /// @return El vector de productos
    ///
    /// @pre cierto
    /// @post No hay cambios en el estado
    static const std::vector<Product>& getProducts();

   private:
    /// @brief Escribe por consola la estructura del rio
    /// Solo usado para ver la estructura del rio. No se usa para ningun caso
    /// del Jutge
    void printRiver() const;

    /// @brief Funcion auxiliar de `redistribute` para hacer la recursion
    /// @param root La ciudad en la que se empieza a redistribuir
    ///
    /// @pre El árbol del río tiene que ser no vacio
    /// @post Se ha comerciado con las ciudades rio arriba. Sus inventarios se
    /// han actualizado segun las reglas de `trade`.
    void redistImpl(const BinTree<std::string>& root);

    /// @brief Encuentra la mejor ruta para el barco en el rio actual
    /// @param data (out) La cantidad de productos comprados y vendidos en la
    /// ruta
    /// @param root Donde empieza la busqueda
    /// @param ship El estado actual del barco
    /// @return Un vector con las direcciones que tiene que tomar el barco para
    /// completar la ruta
    ///
    /// @pre Los datos de `data` tienen que ser mayores de 0. `root` tiene que
    /// ser válido y no vacío. Los datos del barco también se asumen correctos.
    /// @post Se ha encontrado la ruta mas provechosa para el barco. No cambia
    /// el estado del rio
    std::vector<Ship::Direction> findBestRoute(RouteData& data,
                                               const BinTree<std::string>& root,
                                               int buy_curr, int sell_curr);

    /// @brief Funcion auxiliar de `readRiver` para hacer la recursion
    /// @param cityMap El hashmap de las ciudades
    /// @return El arbol que representa el rio
    BinTree<std::string> readRiverImpl(
        std::unordered_map<std::string, City>& cityMap);

   private:
    /// @brief El arbol que representa el rio
    BinTree<std::string> mCityNames;

    /// @brief El mapa de las ciudades. Es el que contiene sus datos.
    std::unordered_map<std::string, City> mCities;

    /// @brief Los datos del barco del rio
    Ship mShip;
};

#endif  // VALLEY_HH
