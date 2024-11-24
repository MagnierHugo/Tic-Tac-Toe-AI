#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <typeindex>
#include <algorithm>
#include <functional>

using _condition_func = std::function<bool()>;


void Str_ToLower(std::string& str);
std::string Str_GetLower(std::string str);


template<typename ContainerType, typename ElementType>
bool Contains(const ContainerType& container, const ElementType& element) {
	return std::find(container.begin(), container.end(), element) != container.end();
}


template<typename ContainerType, typename ElementType>
void EraseElement(ContainerType& container, const ElementType& element) {
	container.erase(std::remove(container.begin(), container.end(), element), container.end());
}


template<typename T>
void AskUser(T& answerHolder, std::string question, _condition_func condition) {
	do {
		std::cout << question << std::endl;
		std::cin >> answerHolder;
	} while (condition());
}


template<typename... T>
void AskUser(std::tuple<T&...> answerHolder, std::string question, _condition_func condition) {
	do {
		std::cout << question << std::endl;
		std::apply([](auto&... args) {((std::cin >> args), ...); }, answerHolder);
	} while (condition());
}