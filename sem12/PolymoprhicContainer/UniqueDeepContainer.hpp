#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

template <typename T>
class PolymorphicContainerUnique
{
private:
	std::vector<std::unique_ptr<T>> collection;

	void copyFrom(const PolymorphicContainerUnique& other);

public:
	PolymorphicContainerUnique() = default;
	PolymorphicContainerUnique(const PolymorphicContainerUnique& other);
	PolymorphicContainerUnique& operator=(const PolymorphicContainerUnique& other);

	PolymorphicContainerUnique(PolymorphicContainerUnique&& other)noexcept = default;
	PolymorphicContainerUnique& operator=(PolymorphicContainerUnique&& other)noexcept =default;

	void add(std::unique_ptr<T> obj);
	void add(const T& obj);
	void remove(const T& obj);

	const T* operator[](size_t index) const;
	T* operator[](size_t index);

	auto begin();
	auto end();

	auto cbegin() const;
	auto cend() const;

};

template<typename T>
inline void PolymorphicContainerUnique<T>::copyFrom(const PolymorphicContainerUnique& other)
{
	std::vector<std::unique_ptr<T>> temp;

	temp.reserve(other.collection.size());

	for (const auto& obj : other.collection) {
		if (obj == nullptr) {
			throw std::invalid_argument("The collection contains an empty pointer");
		}

		temp.push_back(obj->clone());
	}

	collection = std::move(temp);

}

template<typename T>
inline PolymorphicContainerUnique<T>::PolymorphicContainerUnique(const PolymorphicContainerUnique& other)
{
	copyFrom(other);
}

template<typename T>
inline PolymorphicContainerUnique<T>& PolymorphicContainerUnique<T>::operator=(const PolymorphicContainerUnique& other)
{
	if (this != &other) {
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline void PolymorphicContainerUnique<T>::add(std::unique_ptr<T> obj)
{
	collection.push_back(std::move(obj));
}

template<typename T>
inline void PolymorphicContainerUnique<T>::add(const T& obj)
{
	collection.push_back(obj.clone());
}

template<typename T>
inline void PolymorphicContainerUnique<T>::remove(const T& obj)
{
	for (auto it = collection.begin(); it != collection.end(); ++it) {
		if (it->get() == &obj) {
			collection.erase(it);
			return;
		}
	}
}

template<typename T>
const T* PolymorphicContainerUnique<T>::operator[](size_t index) const
{
	if (index < collection.size()) {
		return collection[index].get();
	}
	else {
		throw std::out_of_range("Index out of range");
	}
	return nullptr;
}

template<typename T>
T* PolymorphicContainerUnique<T>::operator[](size_t index)
{
	if (index < collection.size()) {
		return collection[index].get();
	}
	else {
		throw std::out_of_range("Index out of range");
	}
	return nullptr;
}

template<typename T>
auto PolymorphicContainerUnique<T>::begin()
{
	return collection.begin();
}

template<typename T>
auto PolymorphicContainerUnique<T>::end()
{
	return collection.end();
}

template<typename T>
auto PolymorphicContainerUnique<T>::cbegin() const
{
	return collection.cbegin();
}

template<typename T>
auto PolymorphicContainerUnique<T>::cend() const
{
	return collection.cend();
}