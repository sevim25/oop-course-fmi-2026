#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

template <typename T>
class SharedShallow
{
	std::vector<std::shared_ptr<T>> collection;

public:
	void add(std::shared_ptr<T> ptr);
	void remove(const T& obj);

	const std::shared_ptr<T> operator[](size_t index) const;
	std::shared_ptr<T> operator[](size_t index);

};
template<typename T>
inline void SharedShallow<T>::add(std::shared_ptr<T> ptr)
{
	collection.push_back(ptr);
}

template<typename T>
inline void SharedShallow<T>::remove(const T& obj)
{
	for (auto it = collection.begin(); it != collection.end(); ++it) {
		if ((*it).get() == &obj) {
			collection.erase(it);
			return;
		}
	}
}

template<typename T>
const std::shared_ptr<T> SharedShallow<T>::operator[](size_t index) const
{
	if (index < collection.size()) {
		return collection[index];
	}
	else {
		throw std::out_of_range("Index out of range");
	}
}

template<typename T>
std::shared_ptr<T> SharedShallow<T>::operator[](size_t index)
{
	if (index < collection.size()) {
		return collection[index];
	}
	else {
		throw std::out_of_range("Index out of range");
	}
}