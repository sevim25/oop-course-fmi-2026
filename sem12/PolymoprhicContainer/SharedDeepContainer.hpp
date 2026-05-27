#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

template <typename T>
class PContainerShared
{
private:
	std::vector<std::shared_ptr<T>> collection;
	void copyFrom(const PContainerShared& other);

public:
	PContainerShared() = default;
	PContainerShared(const PContainerShared& other);
	PContainerShared& operator=(const PContainerShared& other);

	PContainerShared(PContainerShared&& other)noexcept = default;
	PContainerShared& operator=(PContainerShared&& other)noexcept = default;

	void add(std::shared_ptr<T> ptr);
	void add(const T& obj);
	void remove(const T& obj);

	const std::shared_ptr<T>& operator[](size_t index) const;
	std::shared_ptr<T>& operator[](size_t index);

};

template<typename T>
inline void PContainerShared<T>::copyFrom(const PContainerShared& other)
{
	std::vector<std::shared_ptr<T>> temp;
	temp.reserve(other.collection.size());

	for (const auto& p : other.collection) {
		if (p == nullptr) {
			throw std::invalid_argument("The collection contains an empty pointer");
		}

		temp.push_back(p->clone());
	}

	collection = std::move(temp);
}

template<typename T>
inline PContainerShared<T>::PContainerShared(const PContainerShared& other)
{
	copyFrom(other);
}

template<typename T>
inline PContainerShared<T>& PContainerShared<T>::operator=(const PContainerShared& other)
{
	if (this != &other) {
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline void PContainerShared<T>::add(std::shared_ptr<T> ptr)
{
	collection.push_back(ptr);
}

template<typename T>
inline void PContainerShared<T>::add(const T& obj)
{
	collection.push_back(std::shared_ptr<T>(obj.clone()));
}

template<typename T>
inline void PContainerShared<T>::remove(const T& obj)
{
	for (auto it = collection.begin(); it != collection.end(); ++it) {
		if ((*it).get() == &obj) {
			collection.erase(it);
			return;
		}
	}
}

template<typename T>
const std::shared_ptr<T>& PContainerShared<T>::operator[](size_t index) const
{
	if (index < collection.size()) {
		return collection[index];
	}
	else {
		throw std::out_of_range("Index out of range");
	}
}

template<typename T>
std::shared_ptr<T>& PContainerShared<T>::operator[](size_t index)
{
	if (index < collection.size()) {
		return collection[index];
	}
	else {
		throw std::out_of_range("Index out of range");
	}
}

