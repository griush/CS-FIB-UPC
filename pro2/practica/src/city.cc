/** @file city.cc

    @brief Contiene las definiciones de la clase `City`.
*/
#include "city.hh"
#include <cstddef>
#include <unordered_map>

#include "valley.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

City::City(const std::string& name) {
    mName = name;
    total_mass = 0;
    total_vol = 0;
}

void City::setProductInventory(size_t id, int has, int needs) {
    mInventory[id].has = has;
    mInventory[id].needs = needs;

    mInventoryIds.insert(id);

    // std::cout << Valley::getProducts().at(id).weight << ' '
    //           << Valley::getProducts().at(id).volume << std::endl;

    total_mass += Valley::getProducts().at(id).weight * has;
    total_vol += Valley::getProducts().at(id).volume * has;
}

void City::addProducts(size_t id, int count) {
    mInventory[id].has += count;

    total_mass += Valley::getProducts().at(id).weight * count;
    total_vol += Valley::getProducts().at(id).volume * count;
}

void City::clearInventory() {
    mInventory = std::unordered_map<size_t, ProductDemand>();
    mInventoryIds = std::set<size_t>();
    total_mass = 0;
    total_vol = 0;
}

void City::removeProduct(size_t id) {
    total_mass -= Valley::getProducts().at(id).weight * mInventory.at(id).has;
    total_vol -= Valley::getProducts().at(id).volume * mInventory.at(id).has;
    mInventory.erase(id);
    mInventoryIds.erase(id);
}

void City::print() const {
    for (const auto& id : mInventoryIds) {
        std::cout << id + 1 << ' ' << mInventory.at(id).has << ' '
                  << mInventory.at(id).needs << '\n';
    }

    std::cout << total_mass << ' ' << total_vol << std::endl;
}

void City::getTotalMassVol(int& mass, int& vol) const {
    mass = total_mass;
    vol = total_vol;
}

void City::getProduct(size_t id, int& has, int& needs) const {
    has = mInventory.at(id).has;
    needs = mInventory.at(id).needs;
}
