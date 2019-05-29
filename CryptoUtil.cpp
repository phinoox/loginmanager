#include "CryptoUtil.h"
#include <Poco/Base32Encoder.h>
#include <sstream>
#include <random>
#include <algorithm>

using Poco::Base32Encoder;

std::string const default_chars = 
    "abcdefghijklmnaoqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    
std::string random_string(size_t len = 16, std::string const &allowed_chars = default_chars) {
    std::mt19937_64 gen { std::random_device()() };

    std::uniform_int_distribution<size_t> dist { 0, allowed_chars.length()-1 };

    std::string ret;

    std::generate_n(std::back_inserter(ret), len, [&] { return allowed_chars[dist(gen)]; });
    return ret;
}

std::string generateSecrete()
{
    std::stringstream secret;
    Base32Encoder encoder(secret);
    encoder << random_string();
    encoder.close();
    return secret.str();
    
}

