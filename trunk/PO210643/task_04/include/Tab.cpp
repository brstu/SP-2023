#include "Tab.h"

explicit Tab::Tab(const std::string& url):url(url) {
}

std::string Tab::getUrl() const {
    return url;
}