#include<iostream>
#include<vector>
#include<array>
#include<algorithm>

void SORT_CONTIGUOUS_ARRAY(std::array<int, 15>& CONTIGU_ARRAY, int taille, std::vector<int>& _RESULT_VECTOR_CONTIGU_ARRAY_, bool APPEND_DEBUG);

int main() {
    std::vector<int> RECEPT_CONTIGU_ARRAY;
    std::array<int, 15> CONTIGU_ARRAY = { 4,1,4,5,8,1,2,4,6,4,1,2,4,2,4 };
    SORT_CONTIGUOUS_ARRAY(CONTIGU_ARRAY, CONTIGU_ARRAY.size(), RECEPT_CONTIGU_ARRAY, false);
    for (auto& iteration : RECEPT_CONTIGU_ARRAY)
        std::cout << "contiguous value : " << iteration << std::endl;
    return 0;
}

void SORT_CONTIGUOUS_ARRAY(std::array<int, 15>& CONTIGU_ARRAY, int taille, std::vector<int>& _RESULT_VECTOR_CONTIGU_ARRAY_, bool APPEND_DEBUG) {
    std::vector<int> SORT_CONTIGUOUS_ARRAY_VECTOR;
    int _RESULT_VECTOR_CONTIGU_ARRAY_Number[150] = { 0 }, section = 0;
    int currentSum = CONTIGU_ARRAY[0]; 
    for (int i = 1; i < taille; i++) { 
        if (CONTIGU_ARRAY[i] >= CONTIGU_ARRAY[i - 1]) {
            currentSum += CONTIGU_ARRAY[i];
        }
        else {
            _RESULT_VECTOR_CONTIGU_ARRAY_Number[section++] = currentSum;
            currentSum = CONTIGU_ARRAY[i];
        }
    }
    _RESULT_VECTOR_CONTIGU_ARRAY_Number[section] = currentSum;
    for (int i = 0; i <= section; i++) {
        if (_RESULT_VECTOR_CONTIGU_ARRAY_Number[i] != 0)
            _RESULT_VECTOR_CONTIGU_ARRAY_.push_back(_RESULT_VECTOR_CONTIGU_ARRAY_Number[i]);
    }
    if (APPEND_DEBUG) {
        for (size_t i = 0; i <= section; i++) {
            std::cout << _RESULT_VECTOR_CONTIGU_ARRAY_Number[i] << " ";
        }
        std::cout << std::endl;
    }
    std::sort(_RESULT_VECTOR_CONTIGU_ARRAY_.begin(), _RESULT_VECTOR_CONTIGU_ARRAY_.end());
}

//#include<iostream>
//#include<vector>
//#include<array>
//#include<algorithm>
//
//void SORT_CONTIGUOUS_ARRAY(std::array<int, 15>& CONTIGU_ARRAY, int taille, std::vector<int>& _RESULT_VECTOR_CONTIGU_ARRAY_, bool APPEND_DEBUG);
//
//int main() {
//	std::vector<int> RECEPT_CONTIGU_ARRAY;
//	// tableau contigu de 15 éléments
//	std::array<int, 15> CONTIGU_ARRAY = { 4,1,4,5,8,1,2,4,6,4,1,2,4,2,4 }; //18 - 13 - 7
//	SORT_CONTIGUOUS_ARRAY(CONTIGU_ARRAY, CONTIGU_ARRAY.size(), RECEPT_CONTIGU_ARRAY, false);
//	for (auto& iteration : RECEPT_CONTIGU_ARRAY)
//		std::cout << "contiguous value : " << iteration << std::endl;
//	return 0;
//}
//
//void SORT_CONTIGUOUS_ARRAY(std::array<int, 15>& CONTIGU_ARRAY, int taille, std::vector<int>& _RESULT_VECTOR_CONTIGU_ARRAY_, bool APPEND_DEBUG) {
//	std::vector<int> SORT_CONTIGUOUS_ARRAY_VECTOR;
//	int _RESULT_VECTOR_CONTIGU_ARRAY_Number[150] = { 0 }, section = 1;
//	for (int i = 1; i < taille - 1; i++) { //trie du tableau contigu
//		if (CONTIGU_ARRAY[i] >= CONTIGU_ARRAY[i - 1])
//			_RESULT_VECTOR_CONTIGU_ARRAY_Number[section] += CONTIGU_ARRAY[i];
//		else {
//			_RESULT_VECTOR_CONTIGU_ARRAY_.push_back(_RESULT_VECTOR_CONTIGU_ARRAY_Number[section]);
//			section++;
//		}
//	}
//	for (int i = 0; i < _RESULT_VECTOR_CONTIGU_ARRAY_.size(); i++) { //offset de +1
//		if (_RESULT_VECTOR_CONTIGU_ARRAY_.at(i) != 0)
//			_RESULT_VECTOR_CONTIGU_ARRAY_.at(i) = _RESULT_VECTOR_CONTIGU_ARRAY_.at(i) + 1;
//	}
//	if (APPEND_DEBUG) {
//		for (size_t i = 0; i < 5; i++) {
//			std::cout << _RESULT_VECTOR_CONTIGU_ARRAY_.at(i) << " ";
//		}std::cout << std::endl;
//		for (size_t i = 0; i < 5; i++) {
//			std::cout << _RESULT_VECTOR_CONTIGU_ARRAY_Number[i] << " ";
//		}
//	}
//	std::sort(_RESULT_VECTOR_CONTIGU_ARRAY_.begin(), _RESULT_VECTOR_CONTIGU_ARRAY_.end());
//}


//#include<iostream>
//#include<vector>
//
//void SORT_CONTIGUOUS_ARRAY(int* CONTIGU_ARRAY, int taille, std::vector<int>& _RESULT_VECTOR_CONTIGU_ARRAY_);
//
//int main() {
//	std::vector<int> RECEPT_CONTIGU_ARRAY;
//	// tableau contigu de 15 éléments
//	std::array<int, 15> CONTIGU_ARRAY = { 4,1,4,5,8,1,2,4,6,4,1,2,4,2,4 }; //18 - 13 - 7
//	SORT_CONTIGUOUS_ARRAY(CONTIGU_ARRAY.data(), CONTIGU_ARRAY.size(), RECEPT_CONTIGU_ARRAY);
//	return 0;
//}
//
//void SORT_CONTIGUOUS_ARRAY(int* CONTIGU_ARRAY, int taille, std::vector<int>& _RESULT_VECTOR_CONTIGU_ARRAY_) {
//	int _RESULT_VECTOR_CONTIGU_ARRAY_Number[150] = { 0 }, section = 1;
//	for (int i = 1; i < taille - 1; i++) { //trie du CONTIGU_ARRAYleau contigu
//		if (CONTIGU_ARRAY[i] >= CONTIGU_ARRAY[i - 1])
//			_RESULT_VECTOR_CONTIGU_ARRAY_Number[section] += CONTIGU_ARRAY[i];
//		else {
//			_RESULT_VECTOR_CONTIGU_ARRAY_.push_back(_RESULT_VECTOR_CONTIGU_ARRAY_Number[section]);
//			section++;
//		}
//	}
//	for (int i = 0; i < _RESULT_VECTOR_CONTIGU_ARRAY_.size(); i++) { //offset de +1
//		if (_RESULT_VECTOR_CONTIGU_ARRAY_.at(i) != 0)
//			_RESULT_VECTOR_CONTIGU_ARRAY_.at(i) = _RESULT_VECTOR_CONTIGU_ARRAY_.at(i) + 1;
//	}
//	for (size_t i = 0; i < 5; i++) { // affichage des résultats contigü
//		std::cout << _RESULT_VECTOR_CONTIGU_ARRAY_.at(i) << " ";
//
//	}
//
//}
