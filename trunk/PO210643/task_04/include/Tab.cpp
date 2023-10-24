#include "Tab.h"

Tab::Tab(const std::string& url) {
    this->url = url;
}

std::string Tab::getUrl() const {
    return url;
}