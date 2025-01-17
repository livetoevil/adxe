#pragma once

#include <string>

#include "2d/CCSpriteSheetLoader.h"
#include "base/CCValue.h"
#include "base/CCData.h"

NS_CC_BEGIN

class PlistSpriteSheetLoader : public SpriteSheetLoader
{
public:
    static constexpr uint32_t FORMAT = SpriteSheetFormat::PLIST;

    uint32_t getFormat() override { return FORMAT; }
    void load(const std::string& filePath, SpriteFrameCache& cache) override;
    void load(const std::string& filePath, Texture2D* texture, SpriteFrameCache& cache) override;
    void load(const std::string& filePath, const std::string& textureFileName, SpriteFrameCache& cache) override;
    void load(const Data& content, Texture2D* texture, SpriteFrameCache& cache) override;
    void reload(const std::string& filePath, SpriteFrameCache& cache) override;

protected:
    /*Adds multiple Sprite Frames with a dictionary. The texture will be associated with the created sprite frames.
     */
    void addSpriteFramesWithDictionary(ValueMap& dictionary, Texture2D* texture, const std::string& plist, SpriteFrameCache& cache);

    /*Adds multiple Sprite Frames with a dictionary. The texture will be associated with the created sprite frames.
     */
    void addSpriteFramesWithDictionary(ValueMap& dict, const std::string& texturePath, const std::string& plist, SpriteFrameCache& cache);

    void reloadSpriteFramesWithDictionary(ValueMap& dict, Texture2D* texture, const std::string& plist, SpriteFrameCache& cache);
};

NS_CC_END
