/** @file city.hh

    @brief Contiene las declaraciones de la clase `City` y sus tipos usados.
*/
#ifndef CIUDAD_HH
#define CIUDAD_HH

#ifndef NO_DIAGRAM
#include <set>
#include <string>
#include <unordered_map>
#endif

struct Product;  // fwd decl

/// @brief Almacena la cantidad de un producto que tiene una ciudad y la
/// cantidad que necesita.
struct ProductDemand {
    /// @brief La cantidad de producto que tiene la ciudad.
    int has = -1;

    /// @brief La cantidad de producto que necesita la ciudad.
    int needs = -1;

    /// @brief Constructor por defecto.
    ProductDemand() = default;

    /// @brief Constructor con parámetros.
    /// @param w La cantidad de producto que tiene la ciudad.
    /// @param n La cantidad de producto que necesita la ciudad.
    ProductDemand(int w, int n) : has(w), needs(n) {}
};

class City {
   public:
    /// @brief Constructor por defecto.
    City() = default;

    /// @brief Constructor con parámetros.
    /// @param name El nombre de la ciudad.
    ///
    /// @pre name != ""
    /// @post El nombre de la ciudad es name. Su inventario está vacío.
    City(const std::string& name);

    /// @brief Modifica la cantidad de un producto que tiene la ciudad y la
    /// cantidad que necesita.
    /// @param id La id del producto.
    /// @param has La nueva cantidad de producto que tiene la ciudad.
    /// @param needs La nueva cantidad de producto que necesita la ciudad.
    ///
    /// @pre `id` valida.
    /// @post La ciudad tiene `has` unidades del producto `id` y necesita
    /// `needs` unidades. Modifica los miembros `total_mass` y `total_vol`.
    void setProductInventory(size_t id, int has, int needs);

    /// @brief Añade productos a la ciudad.
    /// @param id La id del producto.
    /// @param count La cantidad de producto que se añade.
    ///
    /// @pre `id` valida.
    /// @post La ciudad tiene `count` unidades más del producto `id`. Modifica
    /// el parametro `has` del producto. Modifica los miembros `total_mass` y
    /// `total_vol`.
    void addProducts(size_t id, int count);

    /// @brief Elimina todos los productos de la ciudad.
    ///
    /// @pre cierto
    /// @post El inventario de la ciudad está vacío. Modifica los miembros
    /// `total_mass` y `total_vol`.
    void clearInventory();

    /// @brief Elimina un producto del inventario de la ciudad.
    /// @param id La id del producto.
    ///
    /// @pre `id` valida.
    /// @post Elimina el producto `id` del inventario de la ciudad. Modifica los
    /// miembros `total_mass` y `total_vol`.
    void removeProduct(size_t id);

    /// @brief Consulta si la ciudad tiene un producto.
    /// @param id La id del producto.
    /// @return true si la ciudad tiene el producto, false en caso contrario.
    /// @pre `id` valida.
    /// @post cierto si la ciudad tiene el producto `id`, falso en caso
    /// contrario. No modifica el inventario.
    inline bool has(size_t id) const {
        return mInventory.find(id) != mInventory.end();
    }

    /// @brief Consulta la cantidad de un producto que tiene la ciudad.
    /// @param id La id del producto.
    /// @return La cantidad de producto que tiene la ciudad.
    ///
    /// @pre `id` valida.
    /// @post La cantidad de producto `id` que tiene la ciudad. No modifica el
    /// inventario.
    inline int hasCount(size_t id) const {
        if (has(id)) return mInventory.at(id).has;
        return 0;
    }

    /// @brief Consulta la cantidad de un producto que necesita la ciudad.
    /// @param id La id del producto.
    /// @return La cantidad de producto que necesita la ciudad.
    ///
    /// @pre `id` valida.
    /// @post La cantidad de producto `id` que necesita la ciudad. No modifica
    /// el inventario.
    inline int needs(size_t id) const {
        if (has(id)) return (mInventory.at(id).needs - mInventory.at(id).has);
        return 0;
    }

    /// @brief Consulta el peso y volumen total del inventario de la ciudad.
    /// @param mass (out) El peso total del inventario.
    /// @param vol (out) El volumen total del inventario.
    ///
    /// @pre cierto
    /// @post `mass` es el peso total del inventario de la ciudad y `vol` es el
    /// volumen total del inventario de la ciudad. No modifica el inventario.
    void getTotalMassVol(int& mass, int& vol) const;

    /// @brief Consulta la cantidad de un producto que tiene y quiere la ciudad.
    /// @param id La id del producto.
    /// @param has (out) La cantidad de producto que tiene la ciudad.
    /// @param needs (out) La cantidad de producto que necesita la ciudad.
    ///
    /// @pre `id` valida.
    /// @post `has` es la cantidad de producto `id` que tiene la ciudad y
    /// `needs` es la cantidad de producto `id` que necesita la ciudad. No
    /// modifica el inventario.
    void getProduct(size_t id, int& has, int& needs) const;

    /// @brief Consulta si la ciudad tiene un excedente de un producto.
    /// @param id La id del producto.
    /// @return true si la ciudad tiene un excedente del producto, false en caso
    /// contrario.
    ///
    /// @pre `id` valida.
    /// @post cierto si la ciudad tiene un excedente del producto `id`, falso en
    /// caso contrario. No modifica el inventario.
    inline bool surplus(size_t id) const {
        return has(id) && mInventory.at(id).has > mInventory.at(id).needs;
    }

    /// @brief Consulta la cantidad de un producto que tiene la ciudad en
    /// exceso.
    /// @param id La id del producto.
    /// @return La cantidad de producto que tiene la ciudad en exceso.
    ///
    /// @pre `id` valida.
    /// @post La cantidad de producto `id` que tiene la ciudad en exceso. No
    /// modifica el inventario.
    inline int surplusCount(size_t id) const {
        if (has(id)) return (mInventory.at(id).has - mInventory.at(id).needs);
        return 0;
    }

    /// @brief Imprime el inventario de la ciudad.
    ///
    /// @pre cierto
    /// @post Imprime el inventario de la ciudad en el formato especificado en
    /// el enunciado.
    void print() const;

    /// @brief Consulta el nombre de la ciudad.
    /// @return El nombre de la ciudad.
    ///
    /// @pre cierto
    /// @post El nombre de la ciudad. No modifica ningún atributo.
    std::string getName() const { return mName; }

    /// @brief Devuelve un iterador al primer elemento del inventario.
    /// @return Un iterador al primer elemento del inventario.
    ///
    /// @pre cierto
    /// @post Un iterador al primer elemento del inventario.
    std::set<size_t>::iterator begin() { return mInventoryIds.begin(); }

    /// @brief Devuelve un iterador al final del inventario.
    /// @return Un iterador al final del inventario.
    ///
    /// @pre cierto
    /// @post Un iterador al final del inventario.
    std::set<size_t>::iterator end() { return mInventoryIds.end(); }

   private:
    /// @brief El nombre de la ciudad.
    std::string mName = "Unnamed city";

    /// @brief El inventario de la ciudad.
    std::unordered_map<size_t, ProductDemand> mInventory;

    /// @brief Las `id` de los productos del inventario ordenadas
    std::set<size_t> mInventoryIds;

    /// @brief El peso total del inventario de la ciudad.
    int total_mass = 0;

    /// @brief El volumen total del inventario de la ciudad.
    int total_vol = 0;
};

#endif  // CIUDAD_HH
