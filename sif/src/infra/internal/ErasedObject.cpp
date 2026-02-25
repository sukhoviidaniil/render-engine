/***************************************************************
 * Project:       Render_Engine
 * File:          ErasedObject.cpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-15
 * Modified:      []
 *
 * Description:   []
 *
 * Contact:
 *   Email:       sukhovii.daniil@gmail.com
 *
 * Disclaimer:
 *   This file is part of Render_Engine.
 *   Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/

#include "infra/internal/ErasedObject.h"

namespace sif::infra::intr {

    ErasedObject::ErasedObject()
        : storage_(nullptr)
        , destroy_(nullptr)
        , type_(TypeId{})
    {}

    ErasedObject::ErasedObject(ErasedObject&& other) noexcept
    : storage_(other.storage_)
    , destroy_(other.destroy_)
    , type_(other.type_) {
        other.storage_ = nullptr;
        other.destroy_ = nullptr;
        other.type_ = 0;
    }

    ErasedObject& ErasedObject::operator=(ErasedObject&& other) noexcept {
        if (this != &other) {
            reset();
            storage_ = other.storage_;
            destroy_ = other.destroy_;
            type_ = other.type_;
            other.storage_ = nullptr;
            other.destroy_ = nullptr;
            other.type_ = 0;
        }
        return *this;
    }

    ErasedObject::~ErasedObject() {
        reset();
    }

    TypeId ErasedObject::type() const {
        return type_;
    }

    bool ErasedObject::valid() const {
        return storage_ != nullptr;
    }

    void  ErasedObject::reset() {
        if (storage_) {
            destroy_(storage_);
            storage_ = nullptr;
        }
    }
}