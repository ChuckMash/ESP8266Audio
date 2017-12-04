/*
  AudioFileSourceID3
  ID3 filter that extracts any ID3 fields and sends to CB function
  
  Copyright (C) 2017  Earle F. Philhower, III

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _AUDIOFILESOURCEID3_H
#define _AUDIOFILESOURCEID3_H

#include <Arduino.h>

#include "AudioFileSource.h"

class AudioFileSourceID3 : public AudioFileSource
{
  public:
    AudioFileSourceID3(AudioFileSource *src);
    virtual ~AudioFileSourceID3() override;
    
    virtual uint32_t read(void *data, uint32_t len) override;
    virtual bool seek(int32_t pos, int dir) override;
    virtual bool close() override;
    virtual bool isOpen() override;
    virtual uint32_t getSize() override;
    virtual uint32_t getPos() override;

    typedef void (*callbackFn)(const char *type, bool isUnicode, int len, AudioFileSource *stream);
    void setCallback(callbackFn f) { cb = f; }

  private:
    AudioFileSource *src;
    bool checked;
    callbackFn cb;
};


#endif
