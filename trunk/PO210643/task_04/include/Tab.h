#pragma once
#ifndef TAB_H
#define TAB_H

#include <string>

class Tab {
public:
    Tab(const std::string& url);
    std::string getUrl() const;

private:
    std::string url;
};
#endif