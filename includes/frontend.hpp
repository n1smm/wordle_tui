/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frontend.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:38:09 by thiew             #+#    #+#             */
/*   Updated: 2025/04/08 14:00:07 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "externLibs.hpp"

#define KEY_TIMEOUT_MS 150

void 		checkInput(std::atomic<bool>	&exit_flag, std::atomic<char> &input_char);
void 		setNonCanonicalMode(bool enable);
