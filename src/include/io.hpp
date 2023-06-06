/// @copyright Amir Nourinia 2022

#pragma once

#include "types.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <exception>


/**
 * @brief print an string to standard output
 * */
inline void print(const String &t_message) {
    std::cout << t_message << std::endl;
}


/**
 * @brief File class representing a text file.
 * */
class File {
public:

    /**
     * @brief Constructor
     * @param content: String, File owns the string. i.e. string is moved into the structure when constructing.
     * @param number_of_lines: u32, number of lines of the file
     * */
    File(String &&content, u32 number_of_lines) : m_content{content}, m_number_of_lines{number_of_lines} {}

    String content() const { return m_content; }

    u32 number_of_lines() const { return m_number_of_lines; }

    /**
     * @brief
     * @return A vector containing different lines of the file.
     * */
    Vector<String> get_lines (const char t_line_seperator = '\n') const {
        const auto ranges = get_lines_ranges(t_line_seperator);
        Vector<String> lines;

        for (const auto& range: ranges) {
            isize n = range.second - range.first;
            String line { m_content.substr(range.first,n)};
            lines.emplace_back( line );
        }
        return lines;
    }

    /**
     * @brief return the number of nodes
     * */
    u64 get_node_count(const char t_line_seperator = '\n') const {
        u64 node_count = 0;

        isize index {0};
        for (; index < m_content.size(); ++index) {
            if (m_content.at(index) == t_line_seperator) {
                // starting from zero, index becomes the count.
                node_count = std::stoull(m_content.substr(0, index));
                break;
            }
        }
        return node_count;
    }

private:
    const String m_content;
    const u32 m_number_of_lines;

    /**
    * @brief
    * @return returns a vector of pairs which shows the ranges of each line
    * */
    Vector<Pair<isize, isize>> get_lines_ranges(const char t_line_seperator = '\n') const {

        Vector<Pair<isize, isize>> lines;

        isize old_index{0};
        isize index{0};
        for (; index < m_content.size(); ++index) {
            if (m_content.at(index) == t_line_seperator) {
                lines.emplace_back(Pair<isize, isize>{old_index, index});
                // update the old index
                old_index = index + 1;
            }
        }
        return lines;
    }
};

/**
 * @brief read a file
 * @param t_file_path file path
 * @return Retruns an Optional<File> in case it was successful; Otherwise, prints the error and return an empty optional.
 * */
inline Optional<File> read_file(const String &t_file_path) {
    std::fstream file;

    try {
        file.open(t_file_path.c_str(), std::ios::in);

        if (file.is_open()) {
            u32 line_count{0};
            String content;
            String line_str;

            while (getline(file, line_str)) {
                content.append(line_str);
                content.append("\n");
                line_str.clear();
                line_count++;
            }
            file.close();
            return File(std::move(content), line_count);
        }
        // else
        return {};
    }
    catch (const std::exception &e) {
        print(e.what());
        return {};
    }
}