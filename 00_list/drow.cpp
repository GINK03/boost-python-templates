#include <boost/python.hpp>
#include <string>

namespace py = boost::python;

class drow{
    public:
        std::string word;
        drow(std::string word): word(word){};
        drow(py::list ch);
        py::list get_chars();
};

drow::drow(py::list l){
    std::string w {""};
    std::string gap {" "};
    std::string token;
    for (int i = 0; i < len(l) ; i++){
        token = py::extract<std::string>(l[i]);
        if (i == len(l) -1){
            w += token;
            break;
        }
        w += token + gap;
    }
    this -> word = w;
}

py::list drow::get_chars(){
    py::list char_vec;
    for (auto c : word){
        char_vec.append(c);
    }
    return char_vec;
}


BOOST_PYTHON_MODULE(drow){
    py::class_<drow>("drow", py::init<std::string>())
        .def(py::init<py::list>())
        .def("get_chars", &drow::get_chars)
        .def_readwrite("word", &drow::word);
}
