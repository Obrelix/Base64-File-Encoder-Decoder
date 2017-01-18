#ifndef BASE64_H
#define BASE64_H
#include <string>
std::string encrypt(unsigned char const* , unsigned int len);
std::string decrypt(std::string const& s);

static const std::string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";


static inline bool is_base64(unsigned char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}

const std::string &SALT1 = "asFH24WEoia124kn";
const std::string &SALT2 = "hd28m+24nS";
const std::string &SALT3 = "jdabnSimOWn24nBS92EU";
const std::string &SALT4 = "82bsfdKNwrWF";

std::string EncryptMix(std::string s)
{

    s = encrypt(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
    s.insert(7, SALT3);
    s += SALT1;
    s = encrypt(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
    s.insert(59, SALT4);
    s = SALT2 + SALT3 + SALT1 + s;
    s = encrypt(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
    s.insert(1, SALT2);
    s.insert(45, SALT3);
    s = encrypt(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
    s.insert(32, SALT4);
    s.insert(62, SALT1);
    s = encrypt(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
    return s;
}
std::string DecryptMix(std::string s)
{
    s = decrypt(s);
    s.erase(62, SALT1.length());
    s.erase(32, SALT4.length());
    s = decrypt(s);
    s.erase(45, SALT3.length());
    s.erase(1, SALT2.length());
    s = decrypt(s);
    s.erase(0,(SALT2.length() + SALT3.length() + SALT1.length()));
    s.erase(59, SALT4.length());
    s = decrypt(s);
    s.erase((s.length()-SALT1.length() -1), SALT1.length());
    s.erase(7, SALT3.length());
    s = decrypt(s);
    return s;
}


std::string encrypt(unsigned char const* bytes_to_encode, unsigned int in_len) {
  std::string ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];

  while (in_len--) {
    char_array_3[i++] = *(bytes_to_encode++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while((i++ < 3))
      ret += '=';

  }

  return ret;

}

std::string decrypt(std::string const& encoded_string) {
  int in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  std::string ret;

  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
    char_array_4[i++] = encoded_string[in_]; in_++;
    if (i ==4) {
      for (i = 0; i <4; i++)
        char_array_4[i] = base64_chars.find(char_array_4[i]);

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
        ret += char_array_3[i];
      i = 0;
    }
  }

  if (i) {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;

    for (j = 0; j <4; j++)
      char_array_4[j] = base64_chars.find(char_array_4[j]);

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
  }

  return ret;
}

#endif // BASE64_H

