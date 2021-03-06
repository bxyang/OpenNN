/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.net                                                                                             */
/*                                                                                                              */
/*   P E R C E P T R O N   L A Y E R   C L A S S   H E A D E R                                                  */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Artificial Intelligence Techniques SL                                                                      */
/*   robertolopez@artelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __PERCEPTRONLAYER_H__
#define __PERCEPTRONLAYER_H__

// System includes

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

// OpenNN includes

#include "perceptron.h"

#include "vector.h"
#include "matrix.h"

namespace OpenNN
{

/// This class represents a layer of perceptrons.
/// Layers of perceptrons will be used to construct multilayer perceptrons. 

class PerceptronLayer
{

public:

   // DEFAULT CONSTRUCTOR

   explicit PerceptronLayer();

   // ARCHITECTURE CONSTRUCTOR 

   explicit PerceptronLayer(const size_t&, const size_t&);

   // COPY CONSTRUCTOR

   PerceptronLayer(const PerceptronLayer&);

   // DESTRUCTOR
   
   virtual ~PerceptronLayer();

   // ASSIGNMENT OPERATOR

   PerceptronLayer& operator =(const PerceptronLayer&);

   // EQUAL TO OPERATOR

   bool operator ==(const PerceptronLayer&) const;

   // GET METHODS

   bool is_empty() const;

   const Vector<Perceptron>& get_perceptrons() const;
   const Perceptron& get_perceptron(const size_t&) const;

   size_t get_inputs_number() const;
   size_t get_perceptrons_number() const;

   // PerceptronLayer parameters

   Vector<double> arrange_biases() const;
   Matrix<double> arrange_synaptic_weights() const;

   size_t count_parameters_number() const;
   Vector<double> arrange_parameters() const;

   size_t count_perceptron_parameters_number() const;
   Vector< Vector<double> > arrange_perceptrons_parameters() const;

   Vector<size_t> count_cumulative_parameters_number() const;

   // Activation functions

   const Perceptron::ActivationFunction& get_activation_function() const;

   string write_activation_function() const;

   // Display messages

   const bool& get_display() const;

   // SET METHODS

   void set();
   void set(const Vector<Perceptron>&);
   void set(const size_t&, const size_t&);
   void set(const PerceptronLayer&);

   void set_default();

   // Architecture

   void set_inputs_number(const size_t&);
   void set_perceptrons_number(const size_t&);

   void set_perceptrons(const Vector<Perceptron>&);
   void set_perceptron(const size_t&, const Perceptron&);

   // PerceptronLayer parameters

   void set_biases(const Vector<double>&);
   void set_synaptic_weights(const Matrix<double>&);

   void set_parameters(const Vector<double>&);

   // Activation functions

   void set_activation_function(const Perceptron::ActivationFunction&);
   void set_activation_function(const string&);

   // Display messages

   void set_display(const bool&);

   // Growing and pruning

   void grow_input();
   void grow_perceptron();
   void grow_perceptrons(const size_t&);


   void prune_input(const size_t&);
   void prune_perceptron(const size_t&);

   // PerceptronLayer initialization methods

   void initialize_random();

   // Parameters initialization methods

   void initialize_biases(const double&); 
   void initialize_synaptic_weights(const double&);

   void initialize_parameters(const double&);

   void randomize_parameters_uniform();
   void randomize_parameters_uniform(const double&, const double&);
   void randomize_parameters_uniform(const Vector<double>&, const Vector<double>&);
   void randomize_parameters_uniform(const Vector< Vector<double> >&);

   void randomize_parameters_normal();
   void randomize_parameters_normal(const double&, const double&);
   void randomize_parameters_normal(const Vector<double>&, const Vector<double>&);
   void randomize_parameters_normal(const Vector< Vector<double> >&);

   // Parameters norm 

   double calculate_parameters_norm() const;

   // Perceptron layer combinations

   Vector<double> calculate_combinations(const Vector<double>&) const;
   Matrix<double> calculate_combinations_Jacobian(const Vector<double>&) const;
   Vector< Matrix<double> > calculate_combinations_Hessian_form(const Vector<double>&) const;

   Vector<double> calculate_combinations(const Vector<double>&, const Vector<double>&) const;
   Matrix<double> calculate_combinations_Jacobian(const Vector<double>&, const Vector<double>&) const;
   Vector< Matrix<double> > calculate_combinations_Hessian_form(const Vector<double>&, const Vector<double>&) const;

   // Perceptron layer activations

   Vector<double> calculate_activations(const Vector<double>&) const;
   Vector<double> calculate_activations_derivatives(const Vector<double>&) const;
   Vector<double> calculate_activations_second_derivatives(const Vector<double>&) const;

   Matrix<double> arrange_activations_Jacobian(const Vector<double>&) const;
   Vector< Matrix<double> > arrange_activations_Hessian_form(const Vector<double>&) const;

   // Perceptron layer outputs

   Vector<double> calculate_outputs(const Vector<double>&) const;
   Matrix<double> calculate_Jacobian(const Vector<double>&) const;
   Vector< Matrix<double> > calculate_Hessian_form(const Vector<double>&) const;

   Vector<double> calculate_outputs(const Vector<double>&, const Vector<double>&) const;
   Matrix<double> calculate_Jacobian(const Vector<double>&, const Vector<double>&) const;
   Vector< Matrix<double> > calculate_Hessian_form(const Vector<double>&, const Vector<double>&) const;

   // Expression methods

   string write_expression(const Vector<string>&, const Vector<string>&) const;

   // Hinton diagram methods

   // Serialization methods


protected:

   // MEMBERS

   /// Vectors of perceptrons which defines the layer.
   /// The size of the vector is equal to the number of perceptrons in the layer.

   Vector<Perceptron> perceptrons;

   /// Display messages to screen. 

   bool display;
};

}

#endif


// OpenNN: Open Neural Networks Library.
// Copyright(C) 2005-2018 Artificial Intelligence Techniques, SL.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software

// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

